# Linked Lists

## What is a Linked List?

A linked list is a sequence of **nodes**, where each node stores:
- a value
- a pointer to the next node

```c
typedef struct sNode {
    int val;
    struct sNode *next;
} tNode;
```

Unlike arrays, nodes are **not necessarily stored next to each other in memory**.

### Important
- `node` → the node itself
- `node->next` → the pointer to the next node
- `ptr = ptr->next` → move the pointer
- `ptr->next = something` → change the connection

---

# Core Pointer Mental Model

### Moving

```c
movingNode = movingNode->next;
```

Moves the pointer without changing the list.

### Reconnecting

```c
movingNode->next = nextNode;
```

Changes the structure of the list.

### Building a list

```c
tail->next = newNode;
tail = newNode;
```

**CONNECT → MOVE**

---

# Reverse Linked List

Core pattern:

```c
next = head->next;
head->next = prev;
prev = head;
head = next;
```

Mental model:

**SAVE → CHANGE → MOVE**

`next` is essential because after:

```c
head->next = prev;
```

the original `head->next` is gone.

---

# Merge Two Sorted Lists

Keep:
- `movingNode` → remembers merged head
- `tail` → current end
- `list1/list2` → unused nodes

```c
tail->next = list1;
tail = tail->next;
```

Reuse existing nodes; no need to allocate new ones.

---

# Cycle Detection

Floyd's algorithm:

```c
slow = slow->next;
fast = fast->next->next;
```

If:

```c
slow == fast
```

the same **node address** was reached → cycle.

Important:

**Same value ≠ same node.**

Never run `freeList()` on a cyclic list.

---

# Reorder List

Three stages:

1. Find middle with `slow/fast`
2. Reverse second half
3. Weave the two halves

Weaving requires saving both next pointers:

```c
nextNode = head->next;
nextPrev = prev->next;
```

Then reconnect:

```c
head->next = prev;
prev->next = nextNode;
```

Mental model:

**SAVE → CONNECT → MOVE**

---

# Remove Nth Node From End

Two pointers:

```c
fast
slow
```

Move `fast` `n` nodes first.

Then move both until `fast == NULL`.

The gap makes `slow` reach the node that needs to be removed.

Important edge case:

```c
if (!fast)
    return head->next;
```

This handles removing the first node.

---

# Copy List With Random Pointer

Used a separate mapping list:

```c
original → copy
```

Two phases:

1. Create every copy + save the mapping.
2. Find each original's `random` node in the mapping and connect the copy.

Important:

When building linked structures:

```c
pairMoving->next = savingPair;
pairMoving = savingPair;
```

Again:

**CONNECT → MOVE**

---

# Add Two Numbers

Each node contains one digit.

Pattern:

**ADD → DIGIT → CARRY → CONNECT → MOVE**

```c
sum = val1 + val2 + carry;
digit = sum % 10;
carry = sum / 10;
```

Continue while:

```c
movingL1 || movingL2 || carry
```

Important devil test:

```text
9999999 + 1
```

Tests the final carry creating a new node.

---

# Find Duplicate Number

The array can be viewed as a **virtual linked list**:

```c
next = nums[index];
```

A duplicate creates a cycle.

Floyd:

```c
slow = nums[slow];
fast = nums[nums[fast]];
```

Then reset:

```c
slow = 0;
```

Move both one step until they meet.

Meeting point = duplicate number.

---

# LRU Cache

Main structure:

**Doubly Linked List**

```text
head                    tail
 ↓                        ↓
LRU → node → node → node → MRU
```

- `head` = least recently used
- `tail` = most recently used

Accessing/updating a node moves it to `tail`.

For a doubly linked list, reconnecting requires both:

```c
node->prev
node->next
```

### `moveToTail`

Detach:

```c
node->prev->next = node->next;
node->next->prev = node->prev;
```

Then attach at tail.

### Optimization

A linked list alone makes lookup `O(n)`.

Adding:

```c
tNode **map;
```

gives direct access:

```c
obj->map[key]
```

so lookup becomes `O(1)`.

The direct-array map used in our local version was a **learning shortcut** based on the key range.

---

# Merge K Sorted Lists

Use a **min-heap**.

Heap stores only:

> **one current node from each non-empty list**

Not every node.

Root:

```c
Queue->node[0]
```

is always the smallest current node.

### Heap indices

```text
left  = 2 * i + 1
right = 2 * i + 2
parent = (i - 1) / 2
```

Last parent:

```c
size / 2 - 1
```

Heapify parents from:

```c
size / 2 - 1
```

down to `0`.

After taking the smallest node:
- replace root with its `next`
- or replace root with the last heap element if that list ended
- decrease heap size
- `bubbleDown`

Important:

**Heap ≠ sorted array.**

Only the heap property is guaranteed.

---

# Reverse Nodes in K-Group

Reverse exactly `k` nodes at a time.

If fewer than `k` nodes remain → leave them unchanged.

Pattern:

**CHECK → REVERSE → RECONNECT → MOVE**

### Check

```c
while (nextGroup && count < k)
{
    nextGroup = nextGroup->next;
    count++;
}
```

If:

```c
count < k
```

stop.

### Reverse

Reuse the normal reverse pattern, but limit it to `k` nodes:

```c
while (head && k--)
{
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
}
```

### Important pointer fact

After reversing:

```text
1 → 2 → 3 → 4
```

becomes:

```text
3 → 2 → 1    4
         ↑    ↑
    movingNode nextGroup
```

The **original group head becomes the new tail**.

Therefore:

```c
movingNode->next = nextGroup;
```

reconnects the reversed group to the remaining list.

### `prevTail`

Needed because each reversed group must connect to the previous group:

```c
prevTail->next = newHead;
```

For the first group there is no `prevTail`, so:

```c
head = newHead;
```

Then:

```c
prevTail = movingNode;
movingNode = nextGroup;
```

---

# Most Important Linked List Tricks

- `ptr = ptr->next` → **move**
- `ptr->next = x` → **reconnect**
- Save `next` **before changing `next`**
- Original head of a reversed section becomes its **tail**
- Use `slow/fast` for middle, cycle, and distance problems
- Use `prevTail` when reconnecting multiple modified sections
- Always think about `NULL` before doing `ptr->next`
- When building a list: **CONNECT → MOVE**
- When reversing: **SAVE → CHANGE → MOVE**
- When manipulating groups: **CHECK → REVERSE → RECONNECT → MOVE**
- Pointer equality checks **node identity/address**, not values
- Be careful with freeing lists after merging/relinking: the nodes may now belong to one combined list
