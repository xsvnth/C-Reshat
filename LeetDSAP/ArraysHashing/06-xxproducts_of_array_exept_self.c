#include <stdlib.h>
int *product_except_self(int *nums, int nsize, int *returnSize){
    int *res = malloc(nsize * sizeof(int));
    int mul = 1;
    for (int i = 0; i < nsize; i++){
        res[i] = mul;
        mul *= nums[i];
    }
    mul = 1;
    for (int i = nsize - 1; i >= 0; i--){
        res[i] *= mul;
        mul *= nums[i];
    }
    *returnSize = nsize;
    return res;
}

#include <stdio.h>
int main(){
    int nums[] = {2, 3 , 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int rsize;
    int *res = product_except_self(nums, size, &rsize);
    printf("[");
    for(int i = 0; i < size; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
}
