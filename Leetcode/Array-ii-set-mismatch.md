## Attempt 1: Failed

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = 0;
        int lost = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                dup = nums[i];
                nums[i] = 0;
            }
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                lost = i + 1;
                break;
            }
        }

        return {dup, lost};
    }
};
```

* I tried two approaches but there were mistakes in both.
* **Approach 1**: Basic mathematics using linear equations in two variables — incorrect math.
* **Approach 2**: Sort-and-search approach — something is wrong with the logic for finding the lost number.
* **Time taken**: 23m 19s

---

## Attempt 2

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exists(n, false);

        sort(nums.begin(), nums.end());

        int dup = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                dup = nums[i];
            }
            exists[nums[i] - 1] = true;
        }
        exists[nums[n - 1] - 1] = true;

        int lost = 0;
        for (int i = 0; i < n; i++) {
            if (!exists[i]) {
                lost = i + 1;
                break;
            }
        }

        return {dup, lost};
    }
};
```

* This is not an optimal solution in terms of time.
* Possibly not optimal in space either.
* Not sure whether a mathematical shortcut exists.
* **Time Complexity**: `O(n log n)`
* **Space Complexity**: `O(n)`

---

## Attempt 3

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> exists(n, 0);

        for (int i = 0; i < n; i++) {
            exists[nums[i] - 1]++;
        }

        int dup = 0;
        int lost = 0;
        for (int i = 0; i < n; i++) {
            if (!exists[i]) {
                lost = i + 1;
            } else if (exists[i] == 2) {
                dup = i + 1;
            }
        }

        return {dup, lost};
    }
};
```

* There is a mathematical trick that can solve this in **O(1)** extra space.
* Tried to optimize the solution to avoid sorting.
* **Time Complexity**: `O(n)`
* **Space Complexity**: `O(n)`
