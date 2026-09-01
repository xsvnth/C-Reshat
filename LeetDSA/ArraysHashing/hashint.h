#ifndef HASH_H
# define HASH_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Hash table entry for integer keys
 */
typedef struct {
    int key;
    int index;
    int used;
} Entry;

/*
 * Integer hash
 */
static unsigned long hashint(int key)
{
    unsigned long h = (unsigned int)key;

    h ^= h >> 16;
    h *= 0x45d9f3b;
    h ^= h >> 16;
    h *= 0x45d9f3b;
    h ^= h >> 16;

    return h;
}

/* zero out the table before use */
static void init(Entry *tab, int size)
{
    for (int i = 0; i < size; i++)
        tab[i].used = 0;
}

/*
 * Find the slot for key:
 * existing slot if present,
 * otherwise first free slot
 */
static int find(Entry *tab, int size, int key)
{
    unsigned long h = hashint(key) % size;

    while (tab[h].used) {
        if (tab[h].key == key)
            break;

        h = (h + 1) % size;
    }

    return h;
}

/* insert or overwrite the value for key */
static void insert(Entry *tab, int size, int key, int index)
{
    int h = find(tab, size, key);

    if (!tab[h].used) {
        tab[h].key = key;
        tab[h].used = 1;
    }

    tab[h].index = index;
}

/* look up key */
static int get(Entry *tab, int size, int key, int *out_index)
{
    int h = find(tab, size, key);

    if (!tab[h].used)
        return 0;

    *out_index = tab[h].index;
    return 1;
}

/* check existence */
static int contains(Entry *tab, int size, int key)
{
    int h = find(tab, size, key);

    return tab[h].used;
}

/* increment count for key */
static void increment(Entry *tab, int size, int key)
{
    int h = find(tab, size, key);

    if (!tab[h].used) {
        tab[h].key = key;
        tab[h].used = 1;
        tab[h].index = 1;
    }
    else
        tab[h].index++;
}

static void remove_key(Entry *tab, int size, int key)
{
    int h = find(tab, size, key);

    if (tab[h].used)
        tab[h].used = 0;
}

#endif
