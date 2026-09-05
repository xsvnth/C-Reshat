#include <stdlib.h>
int icmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);// - (*(int *)a < *(int )*b);
}
int longestConsecutive(int *nums, int numsSize){
    if (!numsSize) return 0;
    qsort(nums, numsSize, sizeof(int), icmp);
    int count = 1, max = 1;
    for (int i = 0; i < numsSize; i++){
        if (nums [i] == nums[i - 1])
            continue;
        if (nums[i] == nums[i - 1] + 1)
            count++;
        else
            count = 1;
        if (count > max)
            max = count;
    }
    return max;
}
#include <stdio.h>
int main(){
    int nums[] = {3, 77, 0, 2, 4, 5, 6, 7, 3, 4, 5, 6};
    int size = sizeof(nums) / sizeof(int);
    printf("and our longest consicutive is : %d\n", longestConsecutive(nums, size));
}
