#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int val;
    int index;
    int used;
}Entry;
int *twosum(int *nums, int numsize, int target, int *retsize){
    int size = numsize * 2;
    int *res = malloc(sizeof(int) * 2);
    Entry *tab = calloc(size, sizeof(Entry));
    for(int i = 0; i < numsize; i++){
        int needed = target - nums[i];
        int h = ((needed % size) + size) % size;
        while(tab[h].used){
            if(tab[h].val == needed){
                res[0] = tab[h].index;
                res[1] = i;
                *retsize = 2;
                free (tab);
                return res;
            }
            h = (h + 1) % size;
        }
        h = ((nums[i] % size) + size) % size;
        while(tab[h].used){
            if(tab[h].val == nums[i])
                break;
            h = (h + 1) % size;
        }
        tab[h].val = nums[i];
        tab[h].index = i;
        tab[h].used = 1;
    }
    free (tab);
    return NULL;
}
int main(){
    int r[] = {9, 2, 8, 4, 3, 9}, target = 19;
    int retsize, numsize = sizeof(r) / sizeof(r[0]);
    int *res = twosum(r, numsize, target, &retsize);
    printf("[");
    for(int i = 0; i < retsize; i++){
        printf("%d, ", res[i]);
    }
    printf("\b\b]\n");
}
/*#include<stdio.h>
int main(){
    int r[] = {3, 4, 5, 9, 4, 3, 4, 8, 9, 6, 4, 5};
    int size = sizeof(r) / sizeof(int);
    int target = 13;
    int retsize = 2;
    int *R = twosum(r, size, target, &retsize);
    printf("[");
    for(int i = 0; i < retsize; i++){
        printf("%d, ", R[i]);
    }
    printf("\b\b]\n");
}*/
