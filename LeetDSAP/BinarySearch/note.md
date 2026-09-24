# Binary Search

## 1. Search Space

Binary Search can search more than array indexes.

The search space can be:

```text
array indexes
matrix indexes
possible answers
partition positions
```

---

## 2. Matrix → Virtual 1D Index

For a sorted matrix, search it as if it were one sorted array.

```c
int i = ...;

row = i / cols;
col = i % cols;
```

No need to actually flatten the matrix.

---

## 3. Binary Search on Answer

Used when the answer has a range of possible values.

Example: Koko:

```text
1 → max(piles)
```

For every `k`, check whether it is feasible.

```c
hours += piles[i] / k;
if (piles[i] % k)
    hours++;
```

If:

```text
hours > h → k too small → search right
hours <= h → k works → search left
```

Use `long long` for accumulated values like `hours`.

---

## 4. Rotated Sorted Array

A rotated sorted array always has a sorted half.

```c
if (nums[left] <= nums[middle])
```

means the left half is sorted.

Otherwise the right half is sorted.

For finding the minimum:

```c
if (nums[middle] > nums[right])
    left = middle + 1;
else
    right = middle;
```

Important:

```c
right = middle;
```

because `middle` can still be the answer.

---

## 5. Rightmost Valid Value

Sometimes Binary Search finds the **last valid position**.

Technique:

```c
if (condition) {
    best = middle;
    left = middle + 1;
}
else
    right = middle - 1;
```

Used in TimeMap to find the latest timestamp `<= target`.

Pattern:

```text
valid → save it → keep searching right
```

---

## 6. Median of Two Sorted Arrays

Different Binary Search technique: **search for the correct partition**, not the median.

```text
nums1: [ left | right ]
              A

nums2: [ left | right ]
              B
```

`A + B` must create the left half of the combined arrays.

### Search the smaller array

Swap arrays if necessary so:

```text
n1Size <= n2Size
```

This keeps the Binary Search space smaller.

### Partition B

```c
partitionB =
    (n1Size + n2Size + 1) / 2 - partitionA;
```

### Boundary tricks

If a partition is at an edge:

```c
left  = INT_MIN;
right = INT_MAX;
```

This lets the normal comparisons still work.

### Valid partition

```c
leftA <= rightB &&
leftB <= rightA
```

### Move partition

If:

```c
leftA > rightB
```

A is too far right:

```c
right = partitionA - 1;
```

Otherwise A is too far left:

```c
left = partitionA + 1;
```

### Median

```c
maxLeft = max(leftA, leftB);
minRight = min(rightA, rightB);
```

Odd:

```text
median = maxLeft
```

Even:

```text
median = (maxLeft + minRight) / 2
```

---

# Key Techniques

* Search **answers**, not only indexes.
* Search a matrix through a **virtual 1D index**.
* Identify a **sorted half** in rotated arrays.
* For "last valid", **save + move right**.
* For partition problems, search for a **valid boundary**.
* `INT_MIN` / `INT_MAX` handle missing partition boundaries.
* `right = middle` when `middle` can still be the answer.
* `long long` for potentially large accumulated values.

