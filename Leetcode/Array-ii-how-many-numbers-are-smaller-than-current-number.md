# Smaller Numbers Than the Current Number  
*A story about patience, comparison, and counting the quiet wins.*

---

## 🧠 Problem in One Breath

Given an array `nums`, for **each element**, count how many numbers in the array are **strictly smaller than it**, and return those counts in a new array.

This is not a sorting story.  
This is a *comparison* story.

---

## 🧩 Mental Model

Think of every number as standing in a room.

Each number looks around and asks:

> “How many people here are shorter than me?”

No shortcuts.  
No pre-processing.  
Just honest, pairwise comparison.

That’s exactly what this solution does.

---

## 🛠️ Strategy (Brute Force, On Purpose)

We use **two loops**:

- The **outer loop** picks the current number.
- The **inner loop** compares it with *every* other number.
- If another number is smaller → increment the counter.

We skip comparing a number with itself.  
Because mirrors lie.

---

## 📦 Implementation (C++)

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        // ans[i] will store how many numbers are smaller than nums[i]
        vector<int> ans(n, 0);

        // Pick each number one by one
        for (int i = 0; i < n; i++) {

            // Compare nums[i] with every other number
            for (int j = 0; j < n; j++) {

                // Skip comparing the number with itself
                if (i == j) continue;

                // If nums[j] is smaller, count it
                if (nums[j] < nums[i]) {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};
```
