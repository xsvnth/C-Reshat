#include <stdlib.h>
int *twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *p1 = numbers, *p2 = numbers + numbersSize - 1;
    int *res = malloc(sizeof(int) * 2);
    while (p1 < p2){
        int trgt = *p1 + *p2;
        if (trgt == target){
            res[0] = p1 - numbers + 1;
            res[1] = p2 - numbers + 1;
            *returnSize = 2;
            return res;
        }
        if (trgt < target)
            p1++;
        else 
            p2--;
    }
    return 0;
}
#include <stdio.h>
int main(){
    int nums[] = {2, 3, 5, 8, 11};
    int nsize = sizeof(nums) / sizeof(int);
    int target = 10;
    int rsize;
    int *res = twoSum(nums, nsize, target, &rsize);
    printf("[");
    for (int i = 0; i < rsize; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
    free(res); 
}
