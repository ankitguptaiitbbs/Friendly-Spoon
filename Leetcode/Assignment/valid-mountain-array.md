# 🏔️ Valid Mountain Array — A Story of One Peak

> *Every good journey has a climb, a peak, and a descent.*

Today, our traveler is an **array of integers**. We must decide:

> **Is this journey a true mountain?**

Let’s tell the story the way the code experiences it.

---

## 🎯 The Mountain Rules (The Laws of the Land)

For an array to earn the title **"Mountain"**, it must obey three immutable rules:

* 🧱 **Length check**: at least **3 elements** (a hill needs space)
* 📈 **Strict climb**: numbers must go **up, up, up**
* 📉 **Strict descent**: after the peak, numbers must go **down, down, down**
* ⛰️ **Exactly one peak**: no plateaus, no second mountains

Formally:

```
arr[0] < arr[1] < ... < arr[i] > arr[i+1] > ... > arr[n-1]
```

---

## 🧠 The Strategy (How the Story Thinks)

We walk **once** through the array — no backtracking, no drama.

We track:

* 🔼 `is_inc` → Are we currently climbing?
* 🔁 `flips` → How many times did we change direction?

A **valid mountain** flips direction **exactly once**:

> climb ➜ **peak** ➜ descend

Anything else? ❌ Not a mountain.

---

## 🧪 Edge Cases (Mountains That Fail the Trial)

| Input       | Why it fails            | Verdict |
| ----------- | ----------------------- | ------- |
| `[2,1]`     | Too short               | ❌       |
| `[3,5,5]`   | Flat peak               | ❌       |
| `[1,2,3]`   | Never comes down        | ❌       |
| `[3,2,1]`   | Never climbs            | ❌       |
| `[0,3,2,1]` | Perfect climb & descent | ✅       |

---

## 🧩 The Code (Executable Story)

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        // A mountain needs at least 3 points
        if(n < 3) return false;

        bool is_inc = true;  // Are we currently climbing?
        int flips = 0;      // Number of direction changes

        for(int i = 0; i < n - 1; i++){
            // Flat ground is forbidden in a mountain
            if(arr[i] == arr[i + 1]) return false;

            if(is_inc){
                // Switch from climbing to descending
                if(arr[i] > arr[i + 1]){
                    flips++;
                    is_inc = false;
                    // Peak cannot be at index 0
                    if(i == 0) return false;
                }
            } else {
                // If we start climbing again, it's invalid
                if(arr[i] < arr[i + 1]){
                    flips++;
                    is_inc = true;
                }
            }
        }
        
        // Exactly one peak is allowed
        return flips == 1;
    }
};
```

---

## ⏱️ Complexity (How Fast the Hike Is)

* 🕒 **Time**: `O(n)` — one clean walk
* 🧠 **Space**: `O(1)` — constant memory

Efficient. Elegant. No wasted steps.

---

## 🌄 Final Verdict

A **valid mountain array** is not about height —

> it’s about **discipline**.

One climb.
One peak.
One descent.

No shortcuts. No plateaus. No second chances. 🏔️✨

---

*Stories end. Mountains remain.*
