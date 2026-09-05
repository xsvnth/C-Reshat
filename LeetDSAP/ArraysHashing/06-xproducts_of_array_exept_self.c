#include <stdlib.h>
int *product_except_self(int *nums, int nsize){
    int *res = malloc(nsize * sizeof(int));
    for (int i = 0; i < nsize; i++){
        int mul = 1;
        for (int j = 0; j < nsize; j++){
            if (i != j)
                mul *= nums[j];
        }
        res[i] = mul;
    }
    return res;
}

#include <stdio.h>
int main(){
    int nums[] = {9, 2, 4, 2, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int *res = product_except_self(nums, size);
    printf("[");
    for(int i = 0; i < size; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
}
