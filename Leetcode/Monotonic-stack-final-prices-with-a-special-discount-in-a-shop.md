# Final Prices With a Special Discount — A Monotonic Stack Story

> *Every price waits for its future. Some futures are kind. Some are cheaper.*

---

## The Problem (State Before)

You walk through a shop, item by item. Each item has a price, and each price is impatient — it wants to know if **a cheaper or equal future** exists.

**Rule of the shop**:

* For item `i`, look to the right.
* Find the **first** index `j > i` such that `prices[j] <= prices[i]`.
* That price becomes the **discount**.
* If no such future exists, the price stands alone.

This is not a search problem.
This is a **waiting problem**.

---

## Why Naive Thinking Fails

A direct approach whispers:

> “For every item, scan right until you find a discount.”

That works — but it leaks performance:

* Time complexity: `O(n²)`
* Repeated work
* No memory of the past

We need something better.
Something that **remembers**.

---

## The Core Insight (State Change)

Instead of asking:

> “Who is my discount?”

We flip the question:

> **“Who am I a discount for?”**

That inversion unlocks a **monotonic stack**.

---

## The Data Structure: A Stack With a Rule

We walk **from right to left**.

The stack represents:

> Prices that are still waiting to become someone’s discount.

### Stack invariant

* The stack is **monotonically increasing** (top is the smallest candidate discount).
* Any price **greater** than the current price is useless and gets discarded.

Why?
Because a higher price can never discount a lower one.

---

## The Algorithm (Executable Narrative)

For each price, from right to left:

1. **Clean the future**

   * Pop prices from the stack that are **greater** than the current price.

2. **Apply discount**

   * If the stack is empty → no discount.
   * Else → discount = stack top.

3. **Register yourself**

   * Push the current price onto the stack.

Each price enters the stack once.
Each price leaves the stack once.

This is linear time.
No wasted motion.

---

## The Code (Implementation)

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> final(n, 0);
        stack<int> st;  // stores candidate discounts

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove prices that cannot act as a discount
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // Apply discount if available
            final[i] = st.empty() ? prices[i]
                                  : prices[i] - st.top();

            // Current price becomes a future candidate
            st.push(prices[i]);
        }
        return final;
    }
};
```

---

## Walking Through an Example

**Input**

```
[8, 4, 6, 2, 3]
```

| Step | Price | Stack Before | Action       | Final Price |
| ---: | ----: | ------------ | ------------ | ----------- |
|    4 |     3 | []           | no discount  | 3           |
|    3 |     2 | [3]          | pop 3        | 2           |
|    2 |     6 | [2]          | discount = 2 | 4           |
|    1 |     4 | [2, 6] → [2] | discount = 2 | 2           |
|    0 |     8 | [2, 4]       | discount = 4 | 4           |

**Output**

```
[4, 2, 4, 2, 3]
```

---

## Complexity (Cost of the Story)

* **Time**: `O(n)`
* **Space**: `O(n)` (stack)

Every operation has purpose.
Nothing repeats.

---

## Why This Pattern Matters

This is not just a shop problem.

This pattern reappears as:

* Next Smaller Element
* Daily Temperatures
* Stock Span
* Histogram Area

Once you see it, you can’t unsee it.

---

## Final Thought

> A monotonic stack is not about stacks.
> It’s about **patience encoded as structure**.

Prices wait.
The future answers.
And the code listens — efficiently.
