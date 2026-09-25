# Median of Two Sorted Arrays

## Main idea

We have **two sorted arrays** and need their median without merging them.

The idea is:

> **Binary search for the correct partition between LEFT and RIGHT halves.**

We always binary-search the **smaller array**.

---

## 1. Partition both arrays

Imagine splitting each array:

```text
nums1: [ LEFT A | RIGHT A ]
nums2: [ LEFT B | RIGHT B ]
```

We want:

```text
all elements in LEFT <= all elements in RIGHT
```

And the total number of elements on the left should be half of the combined arrays.

---

## 2. Why search only one array?

Choose a partition in `nums1`:

```c
partitionA
```

Then the required partition in `nums2` is automatically determined:

```c
partitionB =
    (n1Size + n2Size + 1) / 2 - partitionA;
```

Meaning:

> If I put `partitionA` elements from A on the left, how many elements must come from B to complete the left half?

---

## 3. The four important boundary values

For each partition:

```text
             LEFT        RIGHT

nums1       leftA | rightA
nums2       leftB | rightB
```

They are obtained with:

```c
leftA  = nums1[partitionA - 1];
rightA = nums1[partitionA];

leftB  = nums2[partitionB - 1];
rightB = nums2[partitionB];
```

But when the partition is at an array boundary, there is no element on one side.

So we use:

```c
leftA  = INT_MIN   // nothing on the left
rightA = INT_MAX   // nothing on the right
```

Same for B.

This lets us compare boundaries without special cases later.

---

## 4. When is the partition correct?

We only need to check two conditions:

```c
leftA <= rightB
leftB <= rightA
```

If both are true:

```text
nums1: ... leftA | rightA ...
nums2: ... leftB | rightB ...
             ✓
```

Everything on the LEFT is <= everything on the RIGHT.

So we found the correct partition.

---

## 5. If the partition is wrong

### Case 1: `leftA > rightB`

```c
leftA > rightB
```

We took **too many elements from A**.

So move A's partition LEFT:

```c
right = partitionA - 1;
```

---

### Case 2: `leftB > rightA`

```c
leftB > rightA
```

We didn't take enough elements from A.

So move A's partition RIGHT:

```c
left = partitionA + 1;
```

This is the binary-search part.

---

## 6. Once the partition is correct

The two values around the middle are:

```c
maxLeft = max(leftA, leftB);
minRight = min(rightA, rightB);
```

### Odd number of elements

The median is the largest value on the LEFT:

```c
median = maxLeft;
```

### Even number of elements

The median is:

```c
median = (maxLeft + minRight) / 2.0;
```

---

# Mental Map

```text
Two sorted arrays
        ↓
Search the smaller array
        ↓
Choose partitionA
        ↓
Calculate partitionB
        ↓
Look at:
leftA  rightA
leftB  rightB
        ↓
Is:
leftA <= rightB
AND
leftB <= rightA ?
        ↓
   YES ──────────────→ correct partition
    │                         ↓
    │                    get median
    │
   NO
    ↓
leftA > rightB ?
    │
   YES → move partition LEFT
    │
   NO  → move partition RIGHT
```

## The key thing to remember

**We are NOT binary-searching for the median.**

We are:

> **Binary-searching for the partition that correctly divides the combined sorted data into a LEFT half and a RIGHT half.**

Once that partition is found, the median is just the values around the partition.

### Complexity

```text
Time:  O(log(min(n, m)))
Space: O(1)
```

No merged array is created.

