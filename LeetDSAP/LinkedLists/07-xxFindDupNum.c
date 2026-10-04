int findDuplicate(int *nums, int nSize) {
    int slow  = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
#include <stdio.h>
int main() {
    int nums[] = {
        1, 17, 3, 42, 8, 29, 6, 35, 12, 50,
        4, 21, 31, 9, 45, 14, 27, 39, 2, 48,
        11, 33, 19, 7, 24, 41, 5, 36, 16, 44,
        28, 10, 32, 18, 47, 13, 26, 38, 15, 23,
        40, 22, 34, 30, 43, 25, 37, 20, 46, 49,
        17
    };
    printf("Duplicate: %d\n", findDuplicate(nums, 51));
}
