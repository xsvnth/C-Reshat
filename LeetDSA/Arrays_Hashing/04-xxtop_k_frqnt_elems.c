#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void fill_table(Entry *tab, int tsize, int *nums, int nsize) {
    for (int i = 0; i < nsize; i++) {
        char *keyb = malloc(12);
        sprintf(keyb, "%d", nums[i]);
        increment(tab, tsize, keyb);
    }
}

static void free_keys(Entry *tab, int tsize) {
    for (int i = 0; i < tsize; i++)
        if (tab[i].used) free(tab[i].key);
}

static int cmp(const void *a, const void *b) {
    const Entry *Ea = a, *Eb = b;
    if (Ea->used != Eb->used) return Eb->used - Ea->used;
    return Eb->index - Ea->index;
}

int* topKFrequent(int* nums, int nsize, int k, int* retsize) {
    int tsize = nsize * 2;
    Entry *tab = malloc(sizeof(Entry) * tsize);
    init(tab, tsize);

    fill_table(tab, tsize, nums, nsize);
    qsort(tab, tsize, sizeof(Entry), cmp);

    int *res = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
        res[i] = atoi(tab[i].key);

    free_keys(tab, tsize);
    free(tab);

    *retsize = k;
    return res;
}
/*--------------------------------------------------------------------------
int* topKFrequent(int* nums, int nsize, int k, int* retsize) {
    int tsize = nsize * 2;
    Entry *tab = malloc(sizeof(Entry) * tsize);
    init(tab, tsize);
    for (int i = 0; i < nsize; i++) {
        char *keybuf = malloc(12);
        sprintf(keybuf, "%d", nums[i]);
        increment(tab, tsize, keybuf);
    }

    int **bucket = malloc(sizeof(int *) * (nsize + 1));
    int *bucket_len = malloc(sizeof(int) * (nsize + 1));
    for (int f = 0; f <= nsize; f++) {
        bucket[f] = NULL;
        bucket_len[f] = 0;
    }

    for (int i = 0; i < tsize; i++) {
        if (tab[i].used) {
            int val = atoi(tab[i].key);
            int count = tab[i].index;
            int len = bucket_len[count];
            bucket[count] = realloc(bucket[count], sizeof(int) * (len + 1));
            bucket[count][len] = val;
            bucket_len[count]++;
        }
    }

    int *res = malloc(sizeof(int) * k);
    int collected = 0;
    for (int f = nsize; f >= 1 && collected < k; f--) {
        for (int j = 0; j < bucket_len[f] && collected < k; j++) {
            res[collected] = bucket[f][j];
            collected++;
        }
    }

    for (int f = 0; f <= nsize; f++)
        free(bucket[f]);
    free(bucket);
    free(bucket_len);
    free(tab);

    *retsize = collected;
    return res;
}-------------------------------------------------------------------------*/

int main(){
    int nums[] = {1, 4, 4, 4, 4, 4, 2, 2, 2, 2, 3, 3, 3, 3};
    int size = sizeof(nums) / sizeof(int), k = 2;
    int retsize;
    int *res = topKFrequent(nums, size, k, &retsize);
    printf("[");
    for(int i = 0; i < retsize; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
}
