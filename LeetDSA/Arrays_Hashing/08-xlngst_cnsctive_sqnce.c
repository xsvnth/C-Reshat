#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "hashint.h"

int longestConsecutive(int* nums, int numsSize) {
    if (!numsSize) return 0;
    int tsize = numsSize * 4;
    Entry  *tab = malloc(tsize * sizeof(Entry));
    if (!tab)
        return 0;
    init(tab, tsize);
    for (int i = 0; i < numsSize; i++)
        insert(tab, tsize, nums[i], i);
    int max = 1;
    for (int i = 0; i < numsSize; i++){
        int indx;
        if(get(tab, tsize, nums[i], &indx) && indx != i)
            continue;
        if(get(tab, tsize, nums[i] - 1, &indx))
            continue;
        int count = 1;
        int next = nums[i] + 1;
        while (count < numsSize) {
            int next;
            if (nums[i] > INT_MAX - count)
                break;
            next = nums[i] + count;
            if (!get(tab, tsize, next, &indx))
                break;
            count++;
        }
        if (count > max)
            max = count;
    }
    free(tab);
    return max;
}
#include <stdio.h>
int main(){
    int nums[] = {3, 9, 6, 2, 4, 7, 5};
    int size = sizeof(nums) / sizeof(int);
    printf("and our longet consicutive is : %d\n", longestConsecutive(nums, size));
}
