#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
}

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

/*
int	*top_k(int	*nums, int size, int k, int *retsize){
	int x[10] = {0};
	int used[10] = {0};
    int *res = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) 
		x[nums[i]]++;
	for (int i = 0; i < size; i++) {
		if(x[nums[i]] >= k && !used[nums[i]]) {
			res[i] = nums[i];
			used[nums[i]] = 1;
		}
	}
    *retsize = k;
	return res;
}*/
