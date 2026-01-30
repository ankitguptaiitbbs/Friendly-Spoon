# Daily Temperatures — a story about patience and memory

## The problem, stripped to its bones

Every day has a temperature. Every day asks the same question:

> *How long until something warmer shows up?*

If nothing warmer is coming, the answer is **0**. No hope. No wait.

This is not a forecasting problem. It’s a **next-greater-element** problem wearing a weather costume.

---

## The naive world (and why it burns time)

You *could* look forward from each day, scanning until you find a warmer one.

That works.

It also costs **O(n²)** time — death by a thousand comparisons.

We need memory. We need discipline. We need a structure that remembers *just enough* about the future.

---

## Enter the monotonic stack

Think of the stack as a **watchtower of unresolved days**.

Each index on the stack is a day that hasn’t yet found a warmer future.

**Invariant (the rule we never break):**

> Temperatures stored in the stack are **strictly increasing** from top to bottom.

This invariant is the whole game.

If today is warmer than the day on top of the stack, that day’s waiting ends *now*.

---

## Why we walk from right to left

The future is to the right.

So we start there.

By the time we stand on day `i`, every possible warmer day is already known, filtered, and waiting in the stack.

We are not guessing. We are resolving.

---

## The algorithm as a narrative

For each day `i`, moving from right → left:

1. **Erase weaker futures**
   While the stack holds days that are *not warmer* than today, discard them.

   They failed. They can’t help anyone anymore.

2. **Read the answer**

   * Stack empty? → no warmer day → `0`
   * Stack not empty? → the top is the *nearest warmer day*

3. **Remember today**
   Push `i` onto the stack. Today now waits for its own warmer future.

Every index is pushed once. Every index is popped once.

That’s why this runs in **O(n)** time.

---

## The code (the story made executable)

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> wait(n, 0);
        stack<int> st;  // stores indices of unresolved days

        // walk from the future toward the present
        for (int i = n - 1; i >= 0; i--) {

            // discard days that are not warmer than today
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // if something warmer survives, measure the distance
            wait[i] = st.empty() ? 0 : st.top() - i;

            // today now waits for its own warmer future
            st.push(i);
        }
        return wait;
    }
};
```

---

## A concrete walk-through

Input:

```
[73, 74, 75, 71, 69, 72, 76, 73]
```

Key moments:

* `76` clears the stack — nothing beats it
* `72` waits **1 day** for `76`
* `69` waits **1 day** for `72`
* `71` waits **2 days** for `72`
* `75` waits **4 days** for `76`

Each answer is discovered *once*. No backtracking. No regret.

---

## Mental model to keep

> The stack is not holding temperatures.
>
> It’s holding **questions that haven’t been answered yet**.

The moment a warmer day appears, the question disappears.

That’s why this works.

---

## Complexity (the quiet win)

| Metric | Value    |
| ------ | -------- |
| Time   | **O(n)** |
| Space  | **O(n)** |

No tricks. Just invariants.

---

## Final thought

This pattern shows up everywhere:

* Next greater element
* Stock span
* Largest rectangle in histogram

Different stories.

Same stack.

Once you see it, you can’t unsee it.
