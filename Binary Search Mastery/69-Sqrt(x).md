# Sqrt(x): Finding the Root Without Cheating 🌱

> *Some problems look simple. They’re not testing your math — they’re testing your restraint.*

This is one of those problems.

We’re given a non‑negative integer `x` and asked for its square root, **rounded down**. The catch? No shortcuts. No `pow`. No `sqrt`. No magic.

Just logic. Clean. Deterministic. Honest.

---

## The Constraint That Matters

* `0 ≤ x ≤ 2³¹ − 1`

That upper bound is the real antagonist of this story.

If `x` were small, we could brute force. If overflow didn’t exist, we could be reckless. But here, **carelessness breaks things silently** — the worst kind of bug.

So we need:

* A fast approach ⏱️
* Safe arithmetic 🧯
* A guarantee we never overshoot

That points to exactly one tool.

---

## The Mental Model 🧠

Think of square roots as a **search problem**, not a formula.

We’re looking for the **largest integer `k` such that**:

```
 k × k ≤ x
```

That’s it. Nothing more. Nothing less.

This inequality gives us a **monotonic property**:

* If `k²` is too small → go right
* If `k²` is too big → go left

And monotonic problems love one thing.

> **Binary Search**

---

## The Strategy (High Level)

We search the answer space, not the input space.

* Lowest possible root: `0`
* Highest possible root: `x`

At every step:

1. Pick the middle number
2. Square it
3. Compare it with `x`
4. Shrink the search range

We don’t stop when we *hit* the square root.

We stop when we’ve proven **no larger valid answer exists**.

---

## The Code (The Engine Room) ⚙️

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= x) {
                ans = mid;          // mid is a valid candidate
                low = mid + 1;      // try to find a bigger one
            } else {
                high = mid - 1;     // mid is too large
            }
        }

        return ans;
    }
};
```

---

## Why This Works (The Subtleties) ✨

### 1️⃣ `long long mid`

This is not optional.

When `mid ≈ 46340`, `mid * mid` is already near `2³¹`.

Using `int` here causes **overflow**, which lies quietly and ruins everything.

> Correct logic + wrong type = wrong answer.

---

### 2️⃣ Why We Store `ans`

Binary search doesn’t always land exactly on the square root.

So we remember the **last known good value**.

That’s the root we return.

This pattern shows up everywhere:

* floor problems
* maximize‑under‑constraint problems
* feasibility checks

Learn it once. Reuse it forever.

---

### 3️⃣ Time Complexity

* Search space: `0 → x`
* Halved every iteration

⏱️ **O(log x)**

Even at `x = 2³¹ − 1`, this finishes in ~31 steps.

That’s not fast.

That’s *elegant*.

---

## Example Walkthrough 🔍

**Input:** `x = 8`

| mid | mid² | Decision       |
| --: | ---: | -------------- |
|   4 |   16 | too big → left |
|   1 |    1 | valid → right  |
|   2 |    4 | valid → right  |
|   3 |    9 | too big → left |

Last valid `ans = 2`

✅ Returned.

---

## The Takeaway 🎯

This problem isn’t about square roots.

It’s about:

* Turning math into a search space
* Respecting machine limits
* Writing code that fails loudly instead of silently

You didn’t compute a root.

You **proved** one.

And that’s the kind of code that scales.

---

> *Good solutions give answers.*
>
> *Great solutions explain themselves.*
