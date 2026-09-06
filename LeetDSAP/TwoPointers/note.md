# Two Pointers

### Core idea

Use **2 pointers to eliminate unnecessary work**.

Main question:

> **Why is it safe to move this pointer?**

### Opposite ends

```text
left →       ← right
```

```c
left = arr;
right = arr + n - 1;
```

* `*left` → value
* `left - arr` → index
* `right - left` → distance
* `left < right` → pointers haven't crossed.

### When to think Two Pointers

* **Sorted array** → comparison tells which pointer to move.
* **Two boundaries** → move the side that cannot give a better answer.
* Can replace repeated scanning with **one pass**.

### Two Sum II

```text
sum < target → left++
sum > target → right--
sum == target → found
```

Because sorted:

```text
left ↑  → sum ↑
right ↓ → sum ↓
```

### Three Sum

**Sort first.**

```text
fix i
left = i + 1
right = end
```

Then same Two Sum logic:

```text
sum < 0 → left++
sum > 0 → right--
sum = 0 → save
```

After finding a result → **skip duplicates**.

Also skip duplicate `i` values.

### Container With Most Water

```text
area = (right-left) × min(height[left], height[right])
```

**Move the shorter wall.**

Why?

* Width always decreases.
* Taller wall isn't limiting the area.
* Only moving the shorter wall can possibly increase the limiting height.

### Trapping Rain Water

For position `i`:

```text
water = min(leftMax, rightMax) - height[i]
```

Instead of finding both maxes for every position:

```text
left height < right height → process left
else                       → process right
```

Maintain `leftMax` and `rightMax` **across the loop**.

```text
current >= max → update max
current < max  → water += max-current
```

### Important C tricks

* `right = arr + n - 1` → last element.
* Pointer subtraction works for pointers into the **same array**.
* `int max` ≠ `int *max`.
* If `min()` returns a pointer → `*min(...)` gets the value.
* Don't reset `leftMax/rightMax` inside the loop.
* `realloc()` may move the allocation.

### Complexity

```text
Two Sum II        → O(n), O(1)
Three Sum         → O(n²)
Container         → O(n), O(1)
Rain Water        → O(n), O(1)
```

### Main lesson

> **Don't move a pointer just because you can.**
> Move it because you can **prove the other side cannot give a better answer.**

