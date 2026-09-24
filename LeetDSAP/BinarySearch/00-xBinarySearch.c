int search(int *nums, int nSize, int target) {
    int i = (nSize - 1) / 2;
    int left = 0, right = nSize - 1;
    while (left <= right) {
        int i = (left + right) / 2;
        if (nums[i] == target)
            return i;
        if (target < nums[i])
            right = i - 1;
        else
            left = i + 1;
    }
    return (-1);
}
#include <stdio.h>
int main(){
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(nums) / sizeof(int);
    printf("%d\n", search(nums, size, 8));
}
