# Exclusive Time of Functions — A Stack Story

> *A single-threaded CPU is a quiet place.*
> Only one function breathes at a time. Everyone else waits.

This is the story of how we **measure time honestly** in that world.

---

## Cast of Characters

* **CPU** — single‑threaded, no multitasking, brutally fair
* **Functions (0…n‑1)** — can call each other, even themselves
* **Call Stack (`st`)** — who is *currently* on stage
* **Logs** — immutable facts, not opinions
* **`prev`** — the last moment time was accounted for
* **`times[]`** — the final ledger

---

## The Problem, Reframed

Every log is one of two events:

* `id:start:t` → function `id` **starts at the beginning** of `t`
* `id:end:t` → function `id` **ends at the end** of `t`

Time is **inclusive**. That single detail is where most bugs are born.

Our job is not to measure *how long functions exist* —

> it’s to measure **how long they are actually executing**.

If a function is paused because it called another function,
that time does **not** belong to it.

---

## The Mental Model (Cache This)

> **Only the function on top of the stack is running.**

Every timestamp boundary means **time just passed**.
That time belongs to whoever was on top **before** the boundary.

So the algorithm is really just:

1. Track *who* is running
2. Track *when* we last accounted time
3. Pay the right function before switching context

---

## The Algorithm, as a Timeline

### When a function **starts**

```text
prev ----> time
```

* The currently running function (if any) ran from `prev` → `time`
* Credit that time
* Push the new function
* Move `prev` to `time`

### When a function **ends**

```text
prev ----> time (inclusive)
```

* The ending function ran from `prev` → `time`
* That’s `time - prev + 1`
* Pop it
* Set `prev = time + 1`

That `+1` is not decoration.
It is correctness.

---

## The Code (Executable Story)

```cpp
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);      // final exclusive times
        stack<int> st;                // call stack
        int prev = 0;                 // last accounted timestamp

        for (string log : logs) {
            stringstream ss(log);
            string part;

            getline(ss, part, ':');
            int id = stoi(part);

            getline(ss, part, ':');
            bool is_start = (part == "start");

            getline(ss, part, ':');
            int time = stoi(part);

            if (is_start) {
                // someone was running before this start
                if (!st.empty()) {
                    times[st.top()] += time - prev;
                }
                st.push(id);
                prev = time;
            } else {
                // current function finishes (inclusive)
                times[id] += time - prev + 1;
                st.pop();
                prev = time + 1;
            }
        }

        return times;
    }
};
```

---

## Why This Works

| Concept              | Why it matters             |
| -------------------- | -------------------------- |
| Stack                | Models real call execution |
| `prev`               | Prevents double‑counting   |
| Inclusive end        | Fixes off‑by‑one errors    |
| Credit before switch | Time belongs to the past   |

The code never guesses.
It only accounts for time **when context changes**.

That’s the invariant.

---

## Common Failure Modes (and Why You Avoided Them)

* ❌ Forgetting `+1` on `end`
* ❌ Crediting time *after* pushing a new function
* ❌ Trying to track start times per function

This solution tracks **execution**, not **existence**.
That distinction is everything.

---

## Final Thought

> *Stacks don’t lie.*

If you respect:

* who is on top
* when time changes

…the math becomes inevitable.

No hacks. No special cases. Just clean accounting.

Future you will thank present you for writing it this way.
