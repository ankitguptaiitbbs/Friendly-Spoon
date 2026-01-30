# First Bad Version — A Binary Search Love Letter

> *Every system fails eventually. The only question is: where did it start?* 🔍

---

## 🧩 The Problem, Reframed

You’re not just a product manager — you’re the **guardian of causality**.

* Versions are released in a strict order: `1 → 2 → 3 → ... → n`
* Once **one version goes bad**, *everything after it is doomed*
* You’re given a single oracle:

```cpp
bool isBadVersion(int version);
```

Your mission is simple in words, brutal in scale:

> **Find the first bad version using the fewest possible checks.**

Constraints go up to **2³¹ − 1** versions — which means:

* ❌ Linear scans are too slow
* ❌ Guessing is irresponsible
* ✅ Only logarithmic thinking survives

---

## 🧠 The Insight (aka the State Change)

This is not a guessing game.

This is a **monotonic system**:

* `false false false true true true`

Once `true` appears, it never flips back.

That property unlocks one weapon:

> ### **Binary Search**

Not because it’s fast — but because it **respects structure**.

---

## 🗺️ Mental Model

Think of the versions as a **fault line**:

```
1   2   3   4   5   6   7
🟢  🟢  🟢  🔴  🔴  🔴  🔴
              ↑
        first bad version
```

Binary search doesn’t *inspect everything*.
It asks better questions:

* “Is the middle already broken?”
* If yes → the fault is **to the left**
* If no  → the fault is **to the right**

Each question **cuts the universe in half** ✂️

---

## 🛠️ The Implementation

Clean. Defensive. Overflow-safe.

```cpp
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int ans = high; // pessimistic default

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                ans = mid;        // possible first bad
                high = mid - 1;   // search left
            } else {
                low = mid + 1;    // search right
            }
        }
        return ans;
    }
};
```

---

## 🔍 Why This Works

Let’s annotate the logic like a system trace:

* `low` and `high` define the **current search space**
* `mid` is chosen safely (no integer overflow ⚠️)
* Every `true` response **shrinks the boundary**
* `ans` always remembers the *earliest known failure*

At the end:

* The search space collapses
* `ans` points to the **exact origin of failure**

No wasted calls. No ambiguity.

---

## ⏱️ Complexity Contract

| Metric    | Value                 |
| --------- | --------------------- |
| Time      | **O(log n)** 🚀       |
| Space     | **O(1)** 🧘           |
| API Calls | Minimal & disciplined |

This solution scales — even when `n` doesn’t fit in your head.

---

## 🧠 Takeaway

This isn’t about versions.

It’s about **learning to trust structure**:

* When data is ordered → don’t fight it
* When failures cascade → find the source, not the symptoms
* When constraints grow → *think logarithmically*

> Great engineers don’t debug chaos.
> They isolate the moment things stopped being true. ✨

---

### ✅ Final Thought

Binary search isn’t clever.

It’s **humble**.

It assumes the system makes sense — and then listens carefully until it proves where it broke.

That’s not just good code.
That’s good engineering.
