# 🟩 Max Consecutive Ones — A Walking Counter 🚶‍♂️

## 🧩 The Problem, Stated Plainly

You are given a **binary array** — a long road made only of `0`s and `1`s.

Your task is **not** to count all the ones.

Your task is sharper:

> 🔍 **Find the longest uninterrupted stretch of `1`s.**

No skipping 🚫
No rearranging 🔄
Just one question:

➡️ *How long does the signal stay alive before it drops?*

---

## 🧠 The Mental Model

Imagine yourself walking along the array 🛣️

* `1` 👉 keep walking 🚶‍♀️
* `0` 👉 hit a wall 🧱 → reset

You carry **two counters** in your pocket:

* 🔢 `count` → current streak of consecutive `1`s
* 🏆 `maxi` → the best streak you’ve ever seen

One tracks the **present moment** ⏱️
The other remembers the **best history** 📜

That’s the entire algorithm.

No stacks 📦
No extra memory 🧠
No drama 🎭

---

## 💻 The Code (The Story in Executable Form)

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;   // 🔢 current streak
        int maxi = 0;    // 🏆 best streak so far

        for(int i = 0; i < n; i++){
            count += nums[i];       // ➕ add 1 if nums[i] == 1
            if(!nums[i]) count = 0; // 🔄 reset if we hit a 0
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
```

One loop 🔁
One direction ➡️
One pass only ✨

---

## 🪄 Why `count += nums[i]` Works

This line does quiet, elegant work:

```cpp
count += nums[i];
```

Because:

* `nums[i] == 1` → `count` grows 📈
* `nums[i] == 0` → `count` stays the same 😐

Then immediately:

```cpp
if(!nums[i]) count = 0;
```

So a `0` contributes nothing ❌
**and** forces a reset 🔄

This avoids extra branching 🌿

Small code 🧩
Clear intent 🎯
Fewer moving parts ⚙️

---

## 🧪 Example Walkthrough

Consider:

```text
nums = [1, 1, 0, 1, 1, 1]
```

Step by step 👣

| Index | Value | count | maxi |
| ----: | ----: | ----: | ---: |
|     0 |     1 |     1 |    1 |
|     1 |     1 |     2 |    2 |
|     2 |     0 |     0 |    2 |
|     3 |     1 |     1 |    2 |
|     4 |     1 |     2 |    2 |
|     5 |     1 |     3 |    3 |

🎉 Final answer: **3**

The algorithm never looks back ⏪
It only remembers what matters 💡

---

## ⚡ Complexity (No Surprises)

* ⏱️ **Time:** `O(n)` — one clean pass
* 🧠 **Space:** `O(1)` — just two integers

This is optimal 🏁

Anything more is paying interest you don’t need 💸

---

## 🌟 The Takeaway

This problem isn’t really about arrays.

It’s about **state** 🔄

* A streak = state 📶
* A zero = state reset 🔌
* A maximum = remembered truth 🧠

Once you see that 👀
The solution writes itself ✍️

And once you *feel* it ❤️
You’ll start seeing this pattern everywhere 🌍
