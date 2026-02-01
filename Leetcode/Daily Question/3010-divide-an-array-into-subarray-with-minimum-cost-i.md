# Divide the Array 🧩💰

> *Three cuts. One array. Zero wasted cost.*

---

## 🌱 The Premise

In a quiet land of integers, there lived an array called `nums`.
It wasn’t special at first glance—just numbers, lined up patiently.

But there was a rule of the land:

> **The cost of a subarray is its first element.**

And a challenge from the council:

* Split the array into **exactly 3 contiguous subarrays**
* Pay the **first element** of each subarray as tribute
* **Minimize** the total tribute 💸

---

## 🧠 The Key Insight (The Twist)

The elders noticed something subtle but powerful:

* The **first subarray must always start at index 0**
* So its cost is **locked in** 🔒 → `nums[0]`

No escape. No optimization there.

But the *other two* subarrays?

✨ **Freedom. Choice. Strategy.**

Their costs are simply the **first elements where we choose to split**.

---

## 🔍 The Strategy

Instead of trying every possible split (brute force chaos 😵), the solution does something elegant:

1. Accept the unavoidable:

   * First cost = `nums[0]`
2. Look at the rest of the array
3. Pick the **two smallest numbers**
4. Add them to the cost

That’s it.

Why?

Because:

* Smaller starting numbers → cheaper subarrays
* Order doesn’t matter, only *where the subarrays begin*

---

## 🧮 The Code (Our Protagonist)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0]; // First subarray cost is fixed

        vector<int> minis = {INT_MAX, INT_MAX};
        for(int i = 1; i < n; i++){
            if(nums[i] <= minis[0]){
                minis[1] = minis[0];
                minis[0] = nums[i];
            }
            else if(nums[i] < minis[1]){
                minis[1] = nums[i];
            }
        }
        return ans + minis[0] + minis[1];
    }
};
```

---

## 📦 What This Code Really Does

* 🚪 Locks in the first cost (`nums[0]`)
* 🔎 Scans the remaining elements once
* 🥇 Keeps track of the **two smallest values**
* ➕ Adds them up for the final answer

No extra memory.
No nested loops.
No overthinking.

Just clean, intentional logic.

---

## 🧪 Example Walkthrough

### Input

```text
nums = [10, 3, 1, 1]
```

### Thought Process

* First subarray → cost = **10**
* Remaining numbers → **[3, 1, 1]**
* Two smallest → **1 and 1**

### Final Cost

```text
10 + 1 + 1 = 12
```

✔ Optimal.
✔ Minimal.
✔ Elegant.

---

## 🏁 Final Moral

> Sometimes the problem doesn’t want more computation.
> It wants **better observation** 👀

This solution doesn’t *try everything*.
It **understands what matters**.

And that’s the difference between code that works…
and code that *thinks*. 🧠✨

---

**Happy splitting!** 🚀
