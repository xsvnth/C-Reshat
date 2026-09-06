# Arrays & Hashing

### Core idea

**Hashing = remember information so I don't scan again.**

* `contains(key)` → does it exist?
* `get(key)` → key → stored value
* `increment(key)` → frequency
* Average hash lookup: **O(1)**

### Common patterns

**Contains Duplicate**

* Hash → seen before?
* Or sort → equal neighbors.
* Sorting gives **O(n log n)**.

**Valid Anagram**

* Same length.
* `count[(unsigned char)c]++` for `s`
* `count[(unsigned char)c]--` for `t`
* All counts must return to `0`.

**Two Sum**

```text
need = target - nums[i]
if need exists → answer
else store nums[i] → i
```

One pass with hash → **O(n)**.

**Group Anagrams**

* Anagrams have the same **frequency / sorted representation**.
* Sorted string → hash key.
* Same key → same group.

**Top K Frequent**

* First count frequencies.
* Then select highest frequencies.
* Bucket approach: `bucket[frequency]`.

**Product Except Self**

```text
res[i] = product of everything LEFT
then multiply by product of everything RIGHT
```

Prefix pass + suffix pass → **O(n)**, no division.

**Valid Sudoku**

```text
row[9][10]
col[9][10]
box[9][10]

box = (i / 3) * 3 + (j / 3)
```

Check before inserting.

**Longest Consecutive**

* Put numbers in hash set.
* Start only when `x - 1` **doesn't exist**.
* Then keep checking `x + 1`.
* Each number processed essentially once → **O(n)**.

**Encode / Decode Strings**

```text
length#string
```

Length tells decoder exactly where the string ends.
Works even when string contains spaces, `#`, etc.

### Hash table

```text
hash(key) % table_size → index
collision → (index + 1) % size
```

**Linear probing:** keep moving until key found or free slot.

`find()`:

* existing key → return its slot
* missing key → return first free slot

### C details

* `qsort()` sorts **in place**.
* `strdup()` creates a new string → `free()` it.
* If hash table stores allocated keys → free every stored key.
* `realloc()` can move the allocation.
* `size` = number currently used.
* `capacity` = allocated room.
* `char ***res` → array of groups → each group is `char **`.
* `res[i][j]` = the `j`th string in group `i`.

### Complexity to remember

```text
Hash lookup       → O(1) average
Sorting           → O(n log n)
Two-pass product  → O(n)
Hash + consecutive→ O(n) average
```

### Main lesson

> **What information can I store now so I don't have to search for it again later?**

