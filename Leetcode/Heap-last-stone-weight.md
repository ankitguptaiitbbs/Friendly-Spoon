# 🪨 Last Stone Standing

> *When only the heaviest survive, fairness is enforced by subtraction.*

---

## 🌋 The Setting

A pile of stones lies before us.
Each stone has weight.
Each weight has ego.

The rules of the land are brutal and simple:

* Pick the **two heaviest stones**
* Smash them together 💥
* Equal weights? Both vanish.
* Unequal? The heavier limps away, lighter gone.

This continues until:

* One stone remains 🏆
* Or nothing remains at all (silence…)

---

## 🧠 The Realization

This is not a math problem.
It’s a **priority problem**.

Every turn asks the same question:

> “Who are the two heaviest *right now*?”

If you sort every time, you waste effort.
If you scan every time, you repeat work.

So the story chooses the right tool:

### ⚙️ A Max Heap

* Always gives you the heaviest stone in **O(log n)**
* Rebalances itself without complaint
* Perfect for repetitive dominance contests

---

## 🏗️ Building the Arena

All stones are thrown into the heap.
No judgment. No order. Just weight.

```cpp
priority_queue<int> heap;
for (int stone : stones) heap.push(stone);
```

Now the arena is ready.

---

## ⚔️ The Battle Loop

As long as at least two stones stand:

```cpp
while(!heap.empty() && heap.size() >= 2){
    int x = heap.top(); heap.pop();
    int y = heap.top(); heap.pop();
    if(x != y) heap.push(abs(x - y));
}
```

### What’s really happening here:

* 🥇 The two strongest step forward
* ⚖️ If equal → mutual destruction
* 🩸 If unequal → the difference survives
* 🔄 The survivor re-enters the arena

No special cases.
No branching chaos.
Just rules applied repeatedly.

---

## 🧪 A Walk Through Fire

### Input

```text
[2, 7, 4, 1, 8, 1]
```

### Evolution

* 8 💥 7 → 1 → `[2,4,1,1,1]`
* 4 💥 2 → 2 → `[2,1,1,1]`
* 2 💥 1 → 1 → `[1,1,1]`
* 1 💥 1 → 0 → `[1]`

### Final Stone

```text
1
```

The heap shrinks.
Entropy increases.
One stone remains.

---

## 🏁 The Ending

```cpp
if(!heap.empty()) return heap.top();
return 0;
```

* One survivor? Return its weight.
* None left? Return **0**.

No drama.
Just truth.

---

## 🧭 The Moral

> This problem isn’t about smashing stones.
> It’s about **always knowing who matters most**.

Heaps aren’t fancy.
They’re honest.
They keep power visible.

And in a game where the strongest always fight…

**That’s everything.** 🪨✨

---

*End of match. Arena closed.* 🏟️
