# ➕ Plus One — A Carry’s Journey 🚀

## 🧩 The Problem

You’re handed a **very large number**, not as an integer, but as a **vector of digits**.

* Each element is a single digit (`0–9`)
* Digits go **left → right** from most significant to least
* No leading zeros (this number respects itself 😤)

Your task is deceptively simple:

> **Add exactly one** to this number and return the new digits.

But numbers have memory.
And memory brings… **carry**. ⚡

---

## 🎭 Cast of Characters

| Symbol   | Role                                    |
| -------- | --------------------------------------- |
| `digits` | The number, split into digits 🧮        |
| `i`      | A pointer walking from right to left 👣 |
| `carry`  | The unstoppable `+1` 💥                 |

---

## 🌙 Act I — Enter from the Right

Addition always begins at the **least significant digit**.
So we start from the end of the array:

```cpp
int i = n - 1;
int carry = 1;
```

The `carry` arrives holding a single `+1`.
Our job is to pass it left **only if necessary**.

---

## 🔁 Act II — The Carry Loop (Midnight Arithmetic 🌌)

```cpp
while (i >= 0 && digits[i] >= 9) {
    digits[i] += carry;
    digits[i] %= 10;
    carry = 1;
    i--;
}
```

### What’s happening here?

* If the digit is `9`, adding `1` makes it `10`
* `10 % 10 = 0` → the digit resets 😴
* The carry **survives** and moves left ⬅️

This loop continues until:

* We find a digit **less than 9**, or
* We run out of digits entirely 💣

This is **human arithmetic**, translated line by line.

---

## 🧱 Act III — When the Number Is All 9s 😱

```cpp
if (i == -1) {
    digits.insert(digits.begin(), 1);
}
```

If `i == -1`, it means the carry walked past **every digit**.

Example:

```
999 → 1000
```

We didn’t just modify the number.
We **grew it**.
A new most-significant digit is born 🍼

---

## 🎉 Act IV — The Peaceful Case

```cpp
else {
    digits[i] += 1;
}
```

If we stopped before falling off the array:

* Add `1`
* No further carry
* The system stabilizes 🧘‍♂️

This is the happy path.

---

## 📜 The Full Spell (Complete Code)

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;
        int carry = 1;

        // Propagate carry while digits are 9
        while (i >= 0 && digits[i] >= 9) {
            digits[i] += carry;
            digits[i] %= 10;
            carry = 1;
            i--;
        }

        // If carry survived past the first digit
        if (i == -1) {
            digits.insert(digits.begin(), 1);
        }
        // Otherwise, resolve carry in place
        else {
            digits[i] += 1;
        }

        return digits;
    }
};
```

---

## 🧠 Why This Works

* ⏱ **Time Complexity:** `O(n)` — one clean backward pass
* 🧠 **Space Efficient:** in-place mutation
* 🛡 **Edge-safe:** handles `999…9` without hacks
* ✨ Mirrors real-world addition logic

No tricks. No bloat.
Just state, flow, and resolution.

---

## 🌟 Final Thought

This problem isn’t about adding one.

It’s about **respecting carry**.
About knowing when to **pass responsibility left**.
And when the system must **grow instead of break**.

Small function.
Big idea.

That’s clean code. 💙
