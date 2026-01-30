# 🏙️ Largest Rectangle in Histogram — A Stack Story

> *A story about patience, boundaries, and why sometimes the best move is to **wait**.* 😴📊

---

## 🎯 The Problem (The World We Live In)

You are standing in front of a **histogram skyline**. Each building has:

* a **height** → `heights[i]`
* a **width** → always `1`

Your mission is simple but deceptive:

> **Find the largest rectangular area** that can be formed using contiguous bars.

Example skyline:

```
[2, 1, 5, 6, 2, 3]
```

Some rectangles look tall. Some look wide.
Only **one** is the king. 👑

---

## 🧠 The Core Insight (The Mental Model)

Brute force asks:

> “What if I try every possible rectangle?” 😵

That’s **O(n²)**. Too slow. Rejected at the gates. ❌

Instead, we flip the question:

> **For each bar, how far can it stretch left and right while staying the shortest?**

If a bar is the *minimum height* in a range,
then it defines the rectangle.

So the real problem becomes:

> **When does a bar stop being useful?**

Answer: **When a shorter bar appears.** ⛔

---

## 🧱 The Stack (Our Trusted Tool)

We use a **monotonic increasing stack**:

* It stores **indices**
* Heights are **in increasing order**

Why?
Because the moment we see a **smaller bar**,
we finally know the limits of the taller ones. 💡

---

## 🧨 The Sentinel Trick (The Final Push)

We secretly append:

```
0
```

Why? 🤔

Because some bars never meet a smaller bar on the right.
The sentinel forces **everyone** to be processed.

No unfinished business. No loose ends. 🧹

---

## 🧮 The Algorithm (Step-by-Step Story)

### 🚶‍♂️ Walk Through the Skyline

For each index `i`:

1. 🧐 While the current bar is **shorter** than the stack top:

   * Pop the stack
   * That popped bar just found its **right boundary**

2. 📐 Compute area:

   ```
   height = heights[popped_index]
   width  = i - left_smaller_index - 1
   area   = height * width
   ```

3. 🏆 Update the maximum area

4. 📦 Push the current index

---

## 🧩 The Code (Annotated)

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // Sentinel: forces all bars to be processed
        heights.push_back(0);

        int max_area = 0;
        stack<int> st; // stores indices of increasing heights

        for (int i = 0; i <= n; i++) {
            // Current bar is the "right boundary"
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                // Left boundary is the new stack top
                int width = i - (st.empty() ? -1 : st.top()) - 1;

                max_area = max(max_area, height * width);
            }
            
            // Current bar may help future rectangles
            st.push(i);
        }
        return max_area;
    }
};
```

---

## 🖼️ Visual Intuition

Think of it like this:

* Each bar waits patiently on the stack 🧘‍♂️
* The moment a shorter bar arrives:

  * **“Your reign ends here.”** 👋
  * We measure how far it ruled

Every bar is pushed once and popped once.

> ⚡ **O(n) time. O(n) space.**

Clean. Predictable. Elegant.

---

## 🧠 Why This Works (The Real Lesson)

This problem isn’t about rectangles.

It’s about:

* **Deferring decisions** until enough information arrives
* Letting constraints reveal themselves naturally
* Using structure (the stack) to remember the past

Great algorithms don’t rush.
They **wait for certainty**.

---

## 🏁 Final Takeaway

> 📌 *Every bar gets its moment.*
> 📌 *Every moment has boundaries.*
> 📌 *The stack remembers what you shouldn’t forget.*

Once this clicks,
this pattern shows up **everywhere**:

* Stock Span 📈
* Next Greater Element 🔍
* Daily Temperatures 🌡️

Same story. Different costumes.

Happy stacking! 🚀
