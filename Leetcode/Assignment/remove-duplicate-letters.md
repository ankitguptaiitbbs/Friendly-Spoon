# 🧩 Remove Duplicate Letters — A Stack’s Hero Journey

> *Every character wants to be remembered… but only once.*
> And only in the **smallest lexicographical timeline** possible. ⏳✨

---

## 🌄 The Problem Landscape

You are given a string `s`:

* Letters may **repeat** 🔁
* Each letter must appear **once and only once** ✅
* The final result must be **lexicographically smallest** 🔤⬇️

This isn’t brute force.
This is about **greedy decisions with future awareness**.

---

## 🧠 The Core Idea (Mental Model)

Think of the algorithm as:

> 🏗️ *Building the smallest possible word, one letter at a time, while keeping the door open to future improvements.*

We use three tools:

| Tool     | Role                                           |
| -------- | ---------------------------------------------- |
| `last[]` | 📍 Knows **where each character last appears** |
| `stack`  | 🧱 Builds the answer in order                  |
| `seen`   | 👀 Prevents duplicates                         |

The stack represents **our current best timeline**.

---

## 🗺️ Step 1: Mapping the Future

```cpp
vector<int> last(26, -1);
for (int i = 0; i < n; i++)
    last[s[i] - 'a'] = i;
```

🧭 For every character, we record **its final appearance**.

Why?

* So we know if it’s **safe to remove** a character now and re-add it later.

> If a character won’t appear again… popping it would be **fatal** ☠️

---

## 🏗️ Step 2: Walking the String

```cpp
for (int i = 0; i < n; i++) {
```

We walk left → right, making decisions in real time.

---

### 🚫 Duplicate Guard

```cpp
if (seen.count(s[i])) continue;
```

👮 If we’ve already chosen this character, we **skip it**.

No duplicates allowed. Ever.

---

### 🔁 The Greedy While Loop (The Heart)

```cpp
while (!st.empty() &&
       st.top() >= s[i] &&
       last[st.top() - 'a'] >= i) {
    seen.erase(st.top());
    st.pop();
}
```

This is where the **magic** happens ✨

We pop the stack **only if all three are true**:

1. 📦 Stack is not empty
2. 🔠 Top character is **lexicographically bigger** than current
3. 🔮 That top character **appears again later**

> Translation:
> “I can do better now — and I won’t lose this letter forever.”

---

### ➕ Commit the Character

```cpp
st.push(s[i]);
seen.insert(s[i]);
```

📌 We lock this character into our timeline.

The stack is always:

* Unique
* Increasingly optimal

---

## 🔄 Step 3: Rebuilding the Answer

```cpp
string lss = "";
while (!st.empty()) {
    lss += st.top();
    st.pop();
}
reverse(lss.begin(), lss.end());
```

Stacks pop **backwards**, so we reverse at the end 🔁

🎉 Final result: the smallest possible unique-letter string.

---

## 🧪 Example Walkthrough

### Input

```
"cbacdcbc"
```

### Stack Evolution

| Step | Stack     |
| ---- | --------- |
| c    | c         |
| b    | b         |
| a    | a         |
| c    | a c       |
| d    | a c d     |
| b    | a c d b   |
| c    | (ignored) |

### Output

```
"acdb"
```

💎 Minimal. Unique. Optimal.

---

## ⏱️ Complexity Check

* **Time:** `O(n)` — each character enters and exits the stack once
* **Space:** `O(1)` — at most 26 lowercase letters

Fast. Clean. Deterministic.

---

## 🏁 Final Thought

This algorithm doesn’t just *remove duplicates*.

It **negotiates with the future**,
**undoes bad decisions safely**,
and commits only when certainty is guaranteed.

That’s not just coding — that’s strategy. ♟️🔥

---

✨ *A greedy story with a stack-shaped spine and a lexicographical soul.*
