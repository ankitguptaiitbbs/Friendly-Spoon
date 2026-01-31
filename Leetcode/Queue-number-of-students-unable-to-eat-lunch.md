# 🥪 Number of Students Unable to Eat Lunch — A Cafeteria Queue Story

## 🎒 The Setting

It's lunch break at school. The bell rings 🔔. Students line up in a **queue**.
On the other side of the counter sits a **stack** of sandwiches.

* 🟡 **0** → Circular sandwich
* 🟥 **1** → Square sandwich

Every student has **exactly one preference**. No compromises. No negotiations.

The rules of this cafeteria are simple—but unforgiving.

---

## ⚙️ The Rules of the System

At each step:

1. 👀 The student at the **front of the queue** looks at the **top sandwich**.
2. ✅ If it matches their preference → they take it and leave.
3. 🔄 If it doesn’t → they go to the **end of the queue**.
4. 🛑 This continues until **no one wants the sandwich on top**.

When the system deadlocks, we stop.

Our mission: **count how many students are left hungry** 😢

---

## 🧠 The Core Idea (Mental Model)

Think of this like a loop with a kill-switch:

* A **queue** of students rotating
* A **stack pointer** moving forward
* A **counter** watching for full rotations with no progress

If an entire rotation happens without anyone eating →
🧱 the system is stuck.

---

## 🧪 Example Snapshot

```text
students   = [1,1,1,0,0,1]
sandwiches = [1,0,0,0,1,1]
```

Eventually, only students who want 🟥 remain…
but the sandwich on top is 🟡.

No match. No movement. Game over.

➡️ **3 students remain hungry**

---

## 🧩 The Code (Executable Story)

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int top = 0;               // Points to the top sandwich
        queue<int> q;

        // Load students into a queue
        for (int i = 0; i < n; i++) q.push(students[i]);

        int skipped = 0;            // Counts consecutive skips
        int non_eaters = n;         // Students still in queue

        // Loop until a full rotation happens with no one eating
        while (skipped < non_eaters) {
            if (q.front() == sandwiches[top]) {
                // Student eats the sandwich
                top++;
                non_eaters--;
                q.pop();
                skipped = 0;        // Progress resets the skip counter
            } else {
                // Student goes to the back of the line
                q.push(q.front());
                q.pop();
                skipped++;
            }
        }

        return non_eaters;           // Students who couldn't eat
    }
};
```

---

## 🔍 Why This Works

* **`skipped`** tracks how many students refused the current sandwich
* If `skipped == non_eaters`, no one wants it anymore
* That’s a **deadlock detection** pattern 🧠

No simulation beyond that point matters.

---

## ⏱️ Complexity Check

* **Time:** `O(n²)` worst case (n ≤ 100 → totally fine)
* **Space:** `O(n)` for the queue

Clean. Predictable. Safe.

---

## 🏁 Final Takeaway

This isn’t just about sandwiches.

It’s about:

* Detecting **lack of progress**
* Avoiding infinite loops ♻️
* Modeling real-world constraints with simple data structures

A small problem.
A tight system.
A story with no wasted lines. ✨

Happy coding 🚀
