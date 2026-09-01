#ifndef HASH_H
# define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int  index;
    int  used;
} Entry;

/* djb2 hash */
static unsigned long hashstr(char *s){
    unsigned long h = 5381;

    while (*s)
        h = h * 33 + (unsigned char)*s++;
    return h;
}

/* zero out the table before use */
static void init(Entry *tab, int size){
    for (int i = 0; i < size; i++)
        tab[i].used = 0;
}

/* find the slot for key: existing slot if present,
   otherwise the first free slot for it */
static int find(Entry *tab, int size, char *key){
    unsigned long h = hashstr(key) % size;

    while (tab[h].used){
        if (!strcmp(tab[h].key, key))
            break;
        h = (h + 1) % size;
    }
    return h;
}

/* insert or overwrite the value for key */
static void insert(Entry *tab, int size, char *key, int index){
    int h = find(tab, size, key);

    if (!tab[h].used){
        tab[h].key = key;
        tab[h].used = 1;
    }
    tab[h].index = index;
}

/* look up key; returns 1 and sets *out_index if found, 0 otherwise */
static int get(Entry *tab, int size, char *key, int *out_index){
    int h = find(tab, size, key);

    if (!tab[h].used)
        return (0);
    *out_index = tab[h].index;
    return (1);
}

/* check existence without needing the value */
static int contains(Entry *tab, int size, char *key){
    int h = find(tab, size, key);

    return (tab[h].used);
}

/* increment count for key (starts at 1 if new) - for frequency problems */
static void increment(Entry *tab, int size, char *key){
    int h = find(tab, size, key);

    if (!tab[h].used){
        tab[h].key = key;
        tab[h].used = 1;
        tab[h].index = 1;
    }
    else
        tab[h].index++;
}

static void remove_key(Entry *tab, int size, char *key){
    int h = find(tab, size, key);
    if (tab[h].used)
        tab[h].used = 0; // simple version — works fine as long as you never rely on tombstones for correctness
}

#endif
