#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "hashstr.h"
bool containsdup(int *nums, int nsize){
    int tsize = nsize * 2;
    Entry *tab = malloc(sizeof(Entry) * tsize);
    init(tab, tsize);
    char kbuf[12];
    for (int i = 0; i < nsize; i++){
        sprintf(kbuf, "%d", nums[i]);
        if(contains(tab, tsize, kbuf)){
            free (tab);
            return true;
        }
        insert(tab, tsize, strdup(kbuf), nums[i]);
    }
    free (tab);
    return false;
}

int main(){
    int nums[] = {1, 0, 9, 2, 8, 3, 4, 0};
    int size = sizeof(nums) / sizeof(int);
    printf("res = %d\n", containsdup(nums, size));
}
