# Sliding Window

## Core Idea

Sliding Window = specialized **Two Pointers** technique.

Keep a contiguous range:

```text
[left ........ right]
```

```text
right → expand
left  → shrink
```

Maintain information about the current window instead of recalculating it.

---

## Important Problems

### Longest Substring Without Repeating

Keep frequency of characters **inside the window**.

Duplicate → shrink from left.

```text
window length = right - left + 1
```

---

### Longest Repeating Character Replacement

```text
window size - maxFrequency <= k
```

`maxFrequency` **doesn't need to decrease** when `left` moves.

---

### Permutation in String

**Fixed-size window**:

```text
window size = len(s1)
```

Add `s2[right]`, remove:

```text
s2[right - len]
```

First complete window:

```text
right >= len - 1
```

---

### Minimum Window Substring

```text
required = different characters needed
formed   = requirements currently satisfied
```

Valid window:

```text
formed == required
```

`required` counts **different characters**, not total characters.

---

# Sliding Window Maximum

Naive:

```text
O(n × k)
```

Optimal → **Monotonic Deque**

Deque stores **indices**, not values.

Values are kept decreasing:

```text
[biggest → smaller → smaller]
```

So:

```text
front = current maximum
```

### Deque

```text
Deque[left ... right-1]
```

```text
left++  → remove expired front
right-- → remove useless smaller candidate
right++ → add new index
```

`right` = **next free position**.

Expired:

```text
Deque[left].index <= i - k
```

Useless:

```text
nums[Deque[right-1].index] < nums[i]
```

Maximum:

```text
nums[Deque[left].index]
```

Complexity:

```text
O(n)
```

---

# Mental Model

> **Sliding Window = keep a window and maintain only the information you need.**

```text
EXPAND → MAINTAIN → SHRINK → RECORD
```

Different problems maintain different information:

```text
No duplicates       → frequency
Replacement         → max frequency
Permutation         → frequency
Minimum window      → required / formed
Maximum             → monotonic deque
```

**The goal is always: avoid recalculating the whole window.**

