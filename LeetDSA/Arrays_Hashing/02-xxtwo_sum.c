#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int *twosum(int *nums, int nsize, int target, int *retsize){
    int size = nsize * 2;
    int *res = malloc(sizeof(int) * 2);
    Entry *tab = malloc(sizeof(Entry) * size);
    init(tab, size);
    char searchbuf[12];
    for(int i = 0; i < nsize; i++){
        int needed = target - nums[i];
        sprintf(searchbuf, "%d", needed);
        int idx;
        if (get(tab, size, searchbuf, &idx)){
            res[0] = idx;
            res[1] = i;
            *retsize = 2;
            free(tab);
            return res;
        }
        char *keybuf = malloc(12);          // fresh allocation each insert
        sprintf(keybuf, "%d", nums[i]);
        insert(tab, size, keybuf, i);
    }
    free(tab);
    *retsize = 0;
    return NULL;
}

int main(){
    int arr[] = {4, 3, 5, 9, 8, 0, 6, 4, 6, 8, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12, retsize = 2;
    int *res = twosum(arr, size, target, &retsize);
    printf("[");
    for(int i = 0; i < retsize; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
}
