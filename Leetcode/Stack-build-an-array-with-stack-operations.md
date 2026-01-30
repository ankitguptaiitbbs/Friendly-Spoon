# Build Array With Stack Operations

> *A story about reading numbers, resisting temptation, and only keeping what matters.*

---

## The Problem: Told Like a System

You are handed two things:

* `target` — a **strictly increasing** list of numbers you want to end up with
* `n` — the maximum number you’re allowed to read, starting from `1`

You don’t get to pick numbers directly.

Instead, numbers arrive **one by one** from a stream: `1, 2, 3, ..., n`.

For every number you read, you must decide:

* **Push** → keep it
* **Pop** → discard it immediately

Your job is to output the **exact sequence of operations** that builds `target`.

No more. No less.

---

## The Core Insight (The Mental Model)

Think of this as a **filtering pipeline**.

* You can’t skip numbers
* You can only react when a number arrives
* You stop once `target` is complete

This turns the problem into a simple state machine:

* One pointer walks through incoming numbers (`i`)
* One pointer walks through the `target` array (`j`)

At every step, you ask:

> “Is this number something I need… or something I should let go?”

---

## The Strategy

1. Start reading numbers from `1` to `n`
2. Always **Push** first (you must acknowledge the number)
3. Compare the current number with the current target value

   * If it’s **too small** → **Pop** it
   * If it **matches** → keep it and move forward
4. Stop early once the target is fully built

No backtracking. No guessing. Just forward motion.

---

## The Code (The Engine)

```cpp
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int t = target.size();
        int j = 0;

        for (int i = 1; i <= n && j < t; i++) {
            ans.push_back("Push");

            if (i < target[j]) {
                ans.push_back("Pop");
            } else {
                j++;
            }
        }
        return ans;
    }
};
```

---

## Walkthrough Example

**Input**

```
target = [2, 3]
n = 4
```

**Execution**

| Incoming | Action    | Reason         |
| -------- | --------- | -------------- |
| 1        | Push, Pop | Too small      |
| 2        | Push      | Matches target |
| 3        | Push      | Matches target |

**Output**

```
["Push", "Pop", "Push", "Push"]
```

Once the target is complete, the loop exits.

No unnecessary reads.

---

## Why This Works

* **Single pass** → `O(n)` time
* **No extra data structures** → clean and minimal
* **Early termination** → efficient by design

This is not about simulating a stack.

It’s about **documenting intent** as operations.

---

## The Takeaway

This solution doesn’t fight the constraints — it leans into them.

You don’t skip numbers.
You don’t overthink.
You respond, record, and move on.

Like good documentation.
Like good systems.

> *Keep what you need. Let the rest pass through.*
