#include <stdlib.h>
#include <stdio.h>
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

static void init_table(Entry *tab, int size){
    for (int i = 0; i < size; i++)
        tab[i].used = 0;
}

static int find(Entry *tab, int size, char *key){
    unsigned long h = hashstr(key) % size;
    while (tab[h].used){
        if (!strcmp(tab[h].key, key))
            break;
        h = (h + 1) % size;
    }
    return h;
}

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

int* topKFrequent(int* nums, int nsize, int k, int* retsize) {
    int tsize = nsize * 2;
    Entry *tab = malloc(sizeof(Entry) * tsize);
    init_table(tab, tsize);

    // ---- Phase 1: count frequency of each number ----
    char sbuf[12];
    for (int i = 0; i < nsize; i++) {
        char *keybuf = malloc(12);
        sprintf(keybuf, "%d", nums[i]);
        increment(tab, tsize, keybuf);   // new key -> count 1, existing -> count++
    }

    // ---- Phase 2: bucket values by their frequency ----
    // bucket[f] = growable list of values that occurred exactly f times
    // frequency can range 1..nsize, so we need nsize+1 slots
    int **bucket = malloc(sizeof(int *) * (nsize + 1));
    int *bucket_len = malloc(sizeof(int) * (nsize + 1));
    for (int f = 0; f <= nsize; f++) {
        bucket[f] = NULL;
        bucket_len[f] = 0;
    }

    for (int i = 0; i < tsize; i++) {
        if (tab[i].used) {
            int val = atoi(tab[i].key);
            int count = tab[i].index;     // index was reused to store the count
            int len = bucket_len[count];
            bucket[count] = realloc(bucket[count], sizeof(int) * (len + 1));
            bucket[count][len] = val;
            bucket_len[count]++;
        }
    }

    // ---- Phase 3: walk buckets from highest frequency down, collect k values ----
    int *res = malloc(sizeof(int) * k);
    int collected = 0;
    for (int f = nsize; f >= 1 && collected < k; f--) {
        for (int j = 0; j < bucket_len[f] && collected < k; j++) {
            res[collected] = bucket[f][j];
            collected++;
        }
    }

    // ---- cleanup ----
    for (int f = 0; f <= nsize; f++)
        free(bucket[f]);
    free(bucket);
    free(bucket_len);
    free(tab);

    *retsize = collected;
    return res;
}

int main(){
    int nums[] = {1, 4, 4, 4, 4};
    int size = sizeof(nums) / sizeof(int), k = 1;
    int retsize;
    int *res = topKFrequent(nums, size, k, &retsize);
    printf("[");
    for(int i = 0; i < retsize; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
}
