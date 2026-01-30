# Find All Numbers Disappeared in an Array

> *Nothing here is accidental. Every loop is a state transition. Every mutation leaves a trace.*

---

## Problem in One Breath

You are given an array `nums` of length `n`.

* Each value should be in the range `1 → n`
* Some numbers appear **once**, some **twice**
* Some numbers **never appear at all**

Your task: **return all the numbers from `1` to `n` that never show up in `nums`.**

This solution doesn’t use extra maps or sets.
It builds a *presence table*, then aggressively compacts it.

---

## Mental Model

Think of `ans` as a checklist:

* Index `i` represents number `i + 1`
* Value `i + 1` means *"still missing"*
* Value `0` means *"found in nums"*

We mark what exists.
Then we physically remove what doesn’t matter anymore.

---

## The Code (Annotated)

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Phase 1: Initialize a presence table [1..n]
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = i + 1;

        // Phase 2: Mark numbers that appear
        // Any number seen in nums is invalidated (set to 0)
        for(int i = 0; i < n; i++)
            ans[nums[i] - 1] = 0;

        // Phase 3: Compact the array
        // Push all zeros to the end, then remove them
        for(int i = 0; i < ans.size(); i++){
            while(i < ans.size() && ans[i] == 0){
                swap(ans[i], ans.back());
                ans.pop_back();
            }
        }

        return ans;
    }
};
```

---

## Execution as a Story

### Example

```text
nums = [4,3,2,7,8,2,3,1]
```

#### Step 1 — Initialize

```text
ans = [1,2,3,4,5,6,7,8]
```

#### Step 2 — Mark Seen Numbers

Every number in `nums` flips its slot to `0`:

```text
ans = [0,0,0,0,5,6,0,0]
```

#### Step 3 — Compact

Zeros are swapped to the end and discarded:

```text
ans = [5,6]
```

These are the numbers that never appeared.

---

## Why This Works

* Index = number − 1
* One pass to mark
* One pass to clean
* No extra data structures

You pay with mutation, not memory.

---

## Complexity

| Metric | Cost                       |
| ------ | -------------------------- |
| Time   | `O(n)`                     |
| Space  | `O(n)` (output array only) |

---

## Trade-offs (Honest Ones)

* This **destroys ordering** — intentionally
* The logic is correct but less idiomatic than in-place sign marking
* The compaction loop is subtle and deserves respect

This is not the flashiest solution.
It is a *mechanical* one.

And mechanical solutions are easy to reason about under pressure.

---

## Final Thought

This algorithm doesn’t ask *"what’s missing?"*

It asks:

> *"What can I prove exists — and delete everything else?"*

That mindset scales.
In code. In systems. In thinking.

— End of story.
