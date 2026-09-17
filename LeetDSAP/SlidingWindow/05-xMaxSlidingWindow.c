typedef struct s_Dq {
    int index;
} t_Dq;
#include <stdlib.h>
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *ret = malloc(sizeof(int) * (numsSize - k + 1));
    t_Dq Deque[numsSize];
    int left = 0, right = 0;
    int retIndex = 0;
    for (int i = 0; i < numsSize; i++){
        while (left < right && Deque[left].index <= i - k)
            left++;
        while (right > left && nums[Deque[right - 1].index] < nums[i])
            right--;
        Deque[right].index = i;
        right++;
        if (i >= k - 1){
            ret[retIndex] = nums[Deque[left].index];
            retIndex++;
        }
    }
    *returnSize = retIndex;
    return ret;
}
#include <stdio.h>
int main(){
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int size = sizeof(nums) / sizeof(int);
    int rsize, k = 3;
    int *ret = maxSlidingWindow(nums, size, k, &rsize);
    printf("[");
    for (int i = 0; i < rsize; i++)
        printf("%d, ", ret[i]);
    printf("\b\b]\n");
}
