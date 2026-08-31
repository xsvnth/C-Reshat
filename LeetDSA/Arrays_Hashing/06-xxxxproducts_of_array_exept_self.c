#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *res = malloc(sizeof(int) * numsSize ), mul = 1;
    for (int i = 0; i < numsSize; i++)
        res[i] = mul, mul *= nums[i];
    mul = 1;
    for (int i = numsSize - 1; i >= 0; i--)
        res[i] *= mul, mul *= nums[i];
    *returnSize = numsSize;
    return res; 
}
#include <stdio.h>
int main(){
    int nums[] = {2, 3 , 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int rsize;
    int *res = productExceptSelf(nums, size, &rsize);
    printf("[");
    for(int i = 0; i < size; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");

}
