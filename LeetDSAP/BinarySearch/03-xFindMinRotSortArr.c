int findMin(int *nums, int nSize) {
    int left = 0, right = nSize - 1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > nums[right])
            left = middle + 1;
        else 
            right = middle;
    }
    return nums[left];
}
#include <stdio.h>
int main(){
    int nums[] = {2147483, 21474836, 214748364, 2147483647, 2147, 21474, 214748};
    int size = sizeof(nums) / sizeof(int);
    printf("%d\n", findMin(nums, size));
}
