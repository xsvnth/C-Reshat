# Arrays & Hashing — Consolidated Notes

## 1. Core Ideas

### Array

* Data stored contiguously.
* Access by index → **O(1)**
* Searching → **O(n)**
* Inserting/deleting in the middle → **O(n)**

### Hash Table

Main idea:

> **Turn a value into an index so lookup becomes ~O(1).**

Typical operations:

* Insert → O(1) average
* Search → O(1) average
* Delete → O(1) average

Worst case can become O(n) because of collisions.

---

## 2. Frequency Counting

Very common pattern.

Instead of repeatedly searching an array:

```c
int count[256] = {0};

for (int i = 0; str[i]; i++)
    count[(unsigned char)str[i]]++;
```

Then:

```c
if (count['a'] > 0)
```

means `'a'` exists.

### Important trick

`count[c]++` is doing two things:

1. Find the bucket for `c`
2. Increase its frequency

So:

```text
"banana"

b → 1
a → 3
n → 2
```

---

## 3. Hashing

A hash function converts a key into a number:

```text
key → hash(key) → index
```

Example:

```c
unsigned long h = 5381;

while (*s)
    h = h * 33 + (unsigned char)*s++;
```

Then:

```c
index = h % table_size;
```

### Why `% table_size`?

Because the hash can be HUGE.

The table only has indexes:

```text
0 ... table_size - 1
```

So `%` forces the hash into the valid range.

---

## 4. Collision

Two different keys can produce the same index:

```text
"abc" → 7
"xyz" → 7
```

That's a collision.

One way to solve it:

### Linear probing

If the position is occupied:

```c
h = (h + 1) % size;
```

Keep moving until:

* we find the key
* or we find an empty slot

Conceptually:

```text
index 7 → occupied
index 8 → occupied
index 9 → empty

put key at 9
```

### Important detail

The `% size` is important here too:

```c
(h + 1) % size
```

When `h == size - 1`:

```text
(size - 1 + 1) % size
= size % size
= 0
```

So we wrap around to the beginning.

---

## 5. Hash Map Pattern

General structure:

```text
key → hash → index → bucket → value
```

For example:

```text
"eat"
  ↓
hash("eat")
  ↓
index 13
  ↓
table[13]
  ↓
group #2
```

This lets us avoid scanning every existing group.

---

# Group Anagrams

The important idea:

Two strings belong to the same group if they have the same **key**.

For example:

```text
eat
tea
ate
```

All become the same sorted key:

```text
aet
```

So:

```text
eat → aet
tea → aet
ate → aet
```

Then use the key in a hash table.

---

## 6. Creating a Canonical Key

A canonical key is a representation where equivalent objects produce the same result.

For anagrams:

```text
"eat" → "aet"
"tea" → "aet"
"ate" → "aet"
```

Sorting is one way.

Another way is a frequency key:

```text
a:1
b:0
c:0
...
e:1
...
t:1
```

The frequency representation is often better because it avoids sorting.

---

## 7. `char ***`

This looked confusing at first.

If:

```c
char *str;
```

→ one string.

```c
char **strs;
```

→ array of strings.

```c
char ***res;
```

→ array of groups, where every group is an array of strings.

Think:

```text
char *
   ↓
"eat"

char **
   ↓
["eat", "tea", "ate"]

char ***
   ↓
[
    ["eat", "tea", "ate"],
    ["bat"],
    ["tan", "nat"]
]
```

### Important mental trick

Every `*` adds one level of indirection.

```text
char *      → string
char **     → array of strings
char ***    → array of arrays of strings
```

---

# 8. `res[j][0]`

This was another important little detail.

If:

```c
res[j]
```

is one group:

```text
["eat", "tea", "ate"]
```

then:

```c
res[j][0]
```

means:

```text
"eat"
```

So:

```c
anagram(strs[i], res[j][0])
```

means:

> Compare `strs[i]` with the first string of group `j`.

It's not some special `***res` operation.

The `[]` are simply indexing through the pointer levels.

---

# 9. `malloc`, `calloc`, `realloc`

### `malloc`

Allocates memory but does **not** initialize it.

```c
int *p = malloc(n * sizeof(int));
```

Memory contains indeterminate values.

---

### `calloc`

Allocates memory and initializes it to zero.

```c
int *p = calloc(n, sizeof(int));
```

So for many cases:

```c
calloc(n, sizeof(int))
```

can replace:

```c
malloc(n * sizeof(int))
```

when you want the memory initialized to zero.

---

### `realloc`

Changes the size of an existing allocation.

```c
p = realloc(p, new_size);
```

Useful when you don't know beforehand how many elements you'll need.

### Mental model

```text
malloc  → give me memory
calloc  → give me zeroed memory
realloc → resize my memory
```

---

# 10. Dynamic Array Pattern

When adding elements:

```text
capacity = 4

[ a ][ b ][ c ][ d ]
```

No space left.

Increase capacity:

```text
capacity = 8

[ a ][ b ][ c ][ d ][   ][   ][   ][   ]
```

Then add the new element.

The important distinction:

```text
size     = how many elements I currently have
capacity = how many elements I can store
```

These are NOT the same thing.

---

# 11. `qsort`

When creating a sorted key:

```c
qsort(key, len, sizeof(char), cmp);
```

The important thing is that `qsort` modifies the array **in place**.

So if:

```text
key = "tea"
```

after sorting:

```text
key = "aet"
```

If you don't want to destroy the original string, make a copy first.

---

# 12. Encode / Decode Strings

The key idea is:

> The decoder must know exactly where each string ends.

A delimiter alone is not enough because the delimiter might exist inside the original string.

Use:

```text
length + delimiter + string
```

Example:

```text
"hello"
```

becomes:

```text
5#hello
```

Multiple strings:

```text
["hello", "world"]
```

becomes:

```text
5#hello5#world
```

Decoder:

1. Read digits until `#`
2. Convert them to an integer
3. Read exactly that many characters
4. Repeat

### Important trick

The length can have multiple digits.

Don't assume:

```text
7#...
```

means the length is always one digit.

For:

```text
12345#hello...
```

the length is `12345`.

---

# 13. Calculating Encoded Size

For each string:

```text
length of string
+
number of digits in its length
+
1 delimiter
```

So:

```text
total += strlen(str);
total += number_of_digits(strlen(str));
total += 1;
```

Then allocate the total.

### Important detail

For large lengths, don't manually assume one digit.

Functions such as:

```c
snprintf(...)
```

can help determine how many characters are needed to represent a number.

---

# 14. Complexity — The Question to Always Ask

For every solution, ask:

### Time

> How many times am I visiting the data?

### Space

> How much additional memory am I using?

Example:

```text
Nested loops
→ usually O(n²)

One pass
→ usually O(n)

Hash table lookup
→ O(1) average

Sorting
→ usually O(n log n)
```

---

# 15. The Main Pattern

A huge amount of Arrays & Hashing problems reduce to:

```text
Input
 ↓
Choose a useful representation
 ↓
Store information in a hash table
 ↓
Look it up instead of scanning
 ↓
Reduce O(n²) → O(n)
```

The key question to ask:

> **"What information can I store now so I don't have to search for it later?"**

That's the heart of the pattern.

---

# Small Technical Tricks I Don't Want to Forget

* `size` ≠ `capacity`.
* `char **` = array of strings; `char ***` = array of groups of strings.
* `res[j][0]` means the first string inside group `j`.
* `calloc` is basically `malloc` + zero initialization.
* `realloc` changes the size of an existing allocation.
* `qsort` sorts **in place**.
* Hash `% size` keeps the index inside the table.
* Linear probing uses `(index + 1) % size` to wrap around.
* Hash collisions are normal; the hash table needs a collision strategy.
* Hash lookup is **O(1) average**, not guaranteed O(1).
* For anagrams, you need a **canonical representation** so equivalent strings produce the same key.
* For encode/decode, always encode the **length** because delimiters can appear inside strings.
* Don't assume string lengths are one digit.
* Always distinguish **time complexity** from **space complexity**.

