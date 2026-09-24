int search(int *nums, int nSize, int target) {
    int left = 0, right = nSize - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target)
            return middle;
        if (nums[left] <= nums[middle]) {
            if (target >= nums[left] && target <= nums[middle])
                right = middle - 1;
            else 
                left = middle + 1;
        }
        else {
            if (target <= nums[right] && target >= nums[middle])
                left = middle + 1;
            else 
                right = middle - 1;
        }
    }
    return -1;
}
#include <stdio.h>
int main() {
    //int nums[] = {1, 3};
    //int nums[] = {3, 1};
    int nums[] = {3, 5, 1};
    int size = sizeof(nums) / sizeof(int);
    printf("%d\n", search(nums, size, 3));
}
