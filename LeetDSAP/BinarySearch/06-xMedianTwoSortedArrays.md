# Median of Two Sorted Arrays

## The core idea

We want to split the two sorted arrays into:

```text
nums1: [ LEFT A | RIGHT A ]
nums2: [ LEFT B | RIGHT B ]
```

such that:

```text
all LEFT elements <= all RIGHT elements
```

And we want the **total number of elements on the left** to be half of the combined arrays.

So:

```c
partitionB = (n1Size + n2Size + 1) / 2 - partitionA;
```

This means:

> If I choose `partitionA` elements from `nums1`, how many must I choose from `nums2` to make the left half correct?

---

## Why binary search?

We binary-search where to put the partition in the **smaller array**:

```c
int left = 0, right = n1Size;
```

For every `partitionA`, we look at the four important values:

```text
        LEFT          RIGHT

A     leftA | rightA
B     leftB | rightB
```

A valid partition is:

```c
leftA <= rightB
leftB <= rightA
```

---

## If the partition is wrong

### `leftA > rightB`

Then we took **too many elements from A**:

```text
A: ... leftA | rightA
B: ... rightB
          ↑
     leftA is too big
```

So move A's partition **left**:

```c
right = partitionA - 1;
```

---

### `leftB > rightA`

We didn't take enough elements from A.

So move A's partition **right**:

```c
left = partitionA + 1;
```

---

## Once the partition is valid

The median comes directly from the boundaries:

```c
maxLeft = max(leftA, leftB);
minRight = min(rightA, rightB);
```

### Odd total

```c
median = maxLeft;
```

### Even total

```c
median = (maxLeft + minRight) / 2;
```

---

## Pattern

```text
Two sorted arrays
       ↓
Partition smaller array
       ↓
Calculate matching partition in other array
       ↓
Check boundary condition
       ↓
Too far left?  ← binary search
Too far right? → binary search
       ↓
Valid partition
       ↓
Get median from 4 boundary values
```

