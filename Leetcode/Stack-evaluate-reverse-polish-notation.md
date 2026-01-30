# Evaluating Reverse Polish Notation (RPN)

> *A short story about discipline, order, and a stack that never lies.*

---

## The Problem Setting

We are given an arithmetic expression written in **Reverse Polish Notation (RPN)**.

In RPN, operators come **after** their operands:

```
["2", "1", "+", "3", "*"]
```

This means:

```
(2 + 1) * 3 = 9
```

No parentheses. No ambiguity. Just order.

---

## The Mental Model

Think of the algorithm as a **machine with one rule**:

* Numbers go **in**.
* Operators take **two out**, combine them, and push the result **back in**.

That machine is a **stack**.

Last in. First out. No shortcuts.

---

## Cast of Characters

### 1. The Stack

A memory structure that remembers only what matters **right now**.

```cpp
stack<int> st;
```

It never looks ahead. It never second-guesses. It simply holds state.

---

### 2. The Operator Engine

A small function that does exactly one thing: **combine two numbers**.

```cpp
int operation(int a, int b, string c) {
    if (c == "+") return b + a;
    if (c == "-") return b - a;
    if (c == "/") return b / a;
    return b * a;
}
```

Notice the order:

* `a` is popped **first** (top of stack)
* `b` is popped **second**

This matters.

Subtraction and division are not forgiving.

---

## The Journey Through Tokens

We walk the expression **left to right**.

```cpp
for (int i = 0; i < n; i++) {
```

Each token chooses its fate.

---

### Case 1: The Token Is a Number

Numbers don’t argue. They wait.

```cpp
st.push(stoi(tokens[i]));
```

The stack grows.

---

### Case 2: The Token Is an Operator

Operators demand action.

```cpp
int a = st.top(); st.pop();
int b = st.top(); st.pop();
```

Two values are removed. Order preserved.

The operation happens:

```cpp
st.push(operation(a, b, tokens[i]));
```

State collapses into a new truth.

---

## The End State

After the final token, only **one value remains**.

```cpp
return st.top();
```

That value is the answer.

If the stack has more—or less—something went wrong earlier.

---

## Why This Works

* Every token is processed once → **O(n)** time
* Stack size is bounded by input → **O(n)** space
* No recursion
* No parsing trees

Just discipline.

---

## The Complete Solution

```cpp
class Solution {
public:
    int operation(int a, int b, string c) {
        if (c == "+") return b + a;
        if (c == "-") return b - a;
        if (c == "/") return b / a;
        return b * a;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(operation(a, b, tokens[i]));
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
```

---

## Final Thought

This solution works because it respects **flow**.

* No peeking into the future
* No rewriting the past

Just:

> *Push when you must. Pop when required. Trust the stack.*

That’s not just RPN.

That’s systems thinking.
