# Shuffle the Array

> *Some problems don’t ask for new ideas. They ask for respect for structure.*

---

## The Setup: A Split World

We are given an array called `nums`.

It looks ordinary—until you notice the rule it lives by:

```
[x1, x2, ..., xn, y1, y2, ..., yn]
```

Two halves.

* The **first half** (`x`) is one world
* The **second half** (`y`) is another

They are aligned by **index**, not by proximity.

Our task is not to sort. Not to search. Not to optimize.

Our task is to **interleave**.

---

## The Goal: Restore the Pairing

We want a new array that looks like this:

```
[x1, y1, x2, y2, ..., xn, yn]
```

Every `x` must meet its corresponding `y`.
Order matters.

This is a problem about **mapping intent to position**.

---

## The Key Insight (Five-Second Version)

If `i` is an index in the first half:

* `nums[i]` belongs at position `2*i`
* `nums[i + n]` belongs at position `2*i + 1`

That’s it.

No conditionals. No clever tricks. No temporary buffers.

Just arithmetic and trust in the contract.

---

## The Walkthrough: One Loop, Two Writes

We pre-allocate space for the answer:

* Size: `2 * n`
* Reason: we know exactly how many elements we will place

Then we walk `i` from `0` to `n - 1`.

At each step:

1. Pull one value from the `x` world
2. Pull one value from the `y` world
3. Place them side by side

No element is revisited.
No index is guessed.

---

## The Code (Executable Story)

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[2 * i]     = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }

        return ans;
    }
};
```

---

## Why This Works

Because the problem is already solved **in the input layout**.

We are not discovering relationships.
We are **expressing** them.

The array doesn’t need to be transformed.
It needs to be **revealed**.

---

## Complexity (Because We Always Ask)

* **Time:** `O(n)` — one pass, linear work
* **Space:** `O(n)` — one output array, no extras

This is optimal, readable, and boring in the best way.

---

## Final Thought

Good solutions don’t fight the structure of the data.
They listen to it.

This one hears the rhythm—

> *x, y, x, y…*

—and steps in time.
