# 🎟️ Time Needed to Buy Tickets — A Queue Story

> *A problem about patience, fairness, and one very stubborn line.* 😄

---

## 🧩 The Setup

Imagine a ticket counter with a single rule:

* Only **one ticket per person per second** ⏱️
* After buying a ticket, you **teleport to the back of the line** 🚶‍♂️➡️
* If you’re done buying, you **leave the queue forever** 👋

We’re given:

* `tickets[i]` → how many tickets person `i` wants 🎫
* `k` → the person we care about (our main character)

🎯 **Goal:**
Return the total time (in seconds) until person `k` finishes buying all their tickets.

---

## 🎭 The Cast

Let’s personify the problem:

* Each index = a **person**
* Each value = their **remaining patience** (tickets left)
* The queue = a **circular loop** 🔁

No shortcuts. No skipping. Just pure FIFO justice.

---

## 🧠 The Mental Model

Think of the queue as a **round-robin scheduler** (yes, like an OS 👀):

* One unit of work per turn
* Cycle through everyone
* Stop when our tracked process (`k`) terminates

No simulation of people leaving the queue structure itself.
We just **skip those who are already done**.

---

## ⚙️ The Code (Annotated Story Edition)

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        
        // Copy the ticket requirements so we can safely mutate them
        vector<int> has_to_buy(tickets.begin(), tickets.end());

        int curr = 0;   // Points to the current person in line
        int time = 0;   // Total time elapsed

        // The queue never truly ends — someone is always "next"
        while(true){
            
            // If the current person still needs tickets...
            if(has_to_buy[curr]){
                has_to_buy[curr]--; // They buy exactly one ticket 🎟️
                time++;             // One second passes ⏱️

                // If this is our person (k) and they're done — story ends
                if(curr == k && !has_to_buy[curr])
                    return time;
            }

            // Move to the next person (circular queue)
            curr++;
            curr %= n;
        }
    }
};
```

---

## 🔍 Why This Works

* 🟢 **Faithful simulation** of the problem statement
* 🟢 No complex data structures needed
* 🟢 Constraints are small (`n ≤ 100`, `tickets[i] ≤ 100`)

Worst case time?

```
O(n × max(tickets)) ≤ 10,000 operations
```

That’s pocket change for modern CPUs 💸

---

## 🎬 Example Walkthrough

**Input:**

```
tickets = [2,3,2], k = 2
```

**What happens?**

| Second | Queue State | Action                   |
| -----: | ----------- | ------------------------ |
|      1 | [2,3,2]     | Person 0 buys 🎫         |
|      2 | [3,2,1]     | Person 1 buys            |
|      3 | [2,1,2]     | Person 2 buys            |
|      4 | [1,2,1]     | Person 0 buys            |
|      5 | [2,1]       | Person 1 buys            |
|      6 | [1]         | Person 2 buys & exits 🎉 |

✅ Answer: **6 seconds**

---

## 🏁 Final Thought

This problem isn’t about queues.

It’s about **time slicing**, **fairness**, and **knowing exactly when to stop**.

Once you see the loop, the solution clicks — and never unclicks. 🧠✨
