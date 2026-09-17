# Stack

## Core Idea

Stack = **LIFO** → Last In, First Out.

Use it when you need to keep track of the **most recent unresolved elements**.

```text
push → add
pop  → remove top
top  → inspect top
```

---

## Important Problems

### Valid Parentheses

Opening bracket → **push**

Closing bracket:

```text
empty       → invalid
top mismatch → invalid
match       → pop
```

End:

```c
top == -1
```

---

### Min Stack

Need `getMin()` in **O(1)**.

Keep a second stack/array:

```text
data → values
min  → minimum up to this position
```

```text
getMin() → min[top]
```

> Each element remembers the minimum below it.

---

### Evaluate RPN

```text
number   → push
operator → pop right, pop left
         → calculate
         → push result
```

⚠️ Order matters:

```text
left - right
left / right
```

---

# Monotonic Stack

Used for **next greater/smaller** elements.

Stack stores **indices** when position/distance is needed.

```text
current resolves previous
        ↓
while condition
    pop previous
```

### Daily Temperatures

Keep indices whose answer isn't known yet.

```c
while (!empty && current > temperatures[Top(stack)])
```

Then:

```text
answer[index] = currentIndex - index
```

---

### Car Fleet

Sort cars **closest → farthest** from target.

Calculate:

```text
time = (target - position) / speed
```

```text
time > top → new fleet
time <= top → joins fleet
```

Stack stores **fleet arrival times**.

---

### Largest Rectangle

Monotonic **increasing** stack of indices.

When:

```c
current < heights[Top(stack)]
```

the popped bar found its **right boundary**.

Width:

```text
stack empty → width = i
otherwise    → width = i - Top(stack) - 1
```

```text
area = height × width
```

Trick: process one extra iteration with:

```c
current = 0;
```

This forces remaining bars out of the stack.

---

# Important C Tricks

```text
empty → top == -1
```

If you need the index **and** value:

```c
Top(stack)           // index
heights[Top(stack)]  // value
```

Save before popping:

```c
int popped = Top(stack);
Pop(stack);
```

Dynamic stack:

```text
top      → last element
capacity → allocated space
```

When full → double capacity + `realloc`.

---

# Mental Model

> **Stack = keep the most recent unresolved things.**

For monotonic stacks:

```text
KEEP → WAIT → CURRENT RESOLVES → POP
```

The main question to ask:

> **What does the current element tell me about the elements already in the stack?**

