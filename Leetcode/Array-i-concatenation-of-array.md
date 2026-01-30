# 📦 Concatenation of Array

## A Story in Executable Logic

---

## 🧩 The Problem (State Definition)

We begin with a single array:

* **Name:** `nums`
* **Length:** `n`
* **Nature:** Immutable input, ordered, trusted

The goal is not to transform its values, but to **extend its presence**.

> Create a new array `ans` of length `2n` such that:
>
> * `ans[i] == nums[i]`
> * `ans[i + n] == nums[i]`
>
> for every `0 ≤ i < n`

In human terms: **duplicate the array and place the copy directly after the original**.

This is not a puzzle of creativity. It is a test of discipline.

---

## 🧠 The Mental Model

Think of memory as a clean table with `2n` seats.

* The **first `n` seats** mirror the original array
* The **next `n` seats** repeat the same guests, in the same order

No shuffling. No conditions. No branching paths.

Just a single, predictable walk forward.

---

## ⚙️ The Implementation (Executable Story)

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];       // First half: original
            ans[i + n] = nums[i];   // Second half: copy
        }

        return ans;
    }
};
```

---

## 🪜 Step-by-Step Execution Trace

1. **Measure the input**

   * `n = nums.size()`

2. **Allocate output space**

   * `ans` is created with exactly `2n` slots
   * No resizing later, no surprises

3. **Single pass loop**

   * For each index `i`:

     * Place `nums[i]` at position `i`
     * Place the same value at position `i + n`

4. **Return the result**

   * The array now contains two identical halves

---

## ⏱️ Complexity Analysis

| Metric | Cost                              |
| ------ | --------------------------------- |
| Time   | `O(n)` — one clean pass           |
| Space  | `O(2n)` — intentional duplication |

No hidden allocations. No extra buffers. The cost is explicit and honest.

---

## 🧠 Why This Works

* The loop invariant is simple and stable
* Each element has **exactly two destinations**
* Index math replaces conditionals

This is how small problems should be solved:

> **Clear intent, linear flow, zero drama.**

---

## 🏁 Epilogue

Concatenation is not about copying values.

It’s about respecting order, preserving structure, and expanding state without distortion.

The code doesn’t try to be clever.

It just does the right thing — twice.
