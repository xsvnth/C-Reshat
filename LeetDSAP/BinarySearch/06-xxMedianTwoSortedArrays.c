#include <stdlib.h>

int dcmp(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}
double fndMdianSrtdArr(int* nums1, int n1Size, int* nums2, int n2Size){
    int nums[n1Size + n2Size];
    for (int i = 0; i < n1Size; i++)
        nums[i] = nums1[i];
    int j = 0;
    for (int i = n1Size; i < n1Size + n2Size; i++) 
        nums[i] = nums2[j++];
    qsort(nums, n1Size + n2Size, sizeof(int), dcmp);
    int left = 0, right = n1Size + n2Size - 1;
    if ((n1Size + n2Size) % 2) {
        int middle = left + (right - left) / 2;
        return nums[middle];
    }
    else {
        int middle = left + (right - left) / 2;
        double ret = (nums[middle] + nums[middle + 1]) / 2.0;
        return ret;
    }
    return 0;
}
#include <stdio.h>
int main() {
    //int a[] = {1, 2, 2, 2, 2};
    //int b[] = {2, 2, 2, 3};
    int a[] = {-1000000, -5, 0, 5, 1000000};
    int b[] = {-999999, -4, 1, 6};
    int asize = sizeof(a) / sizeof(int);
    int bsize = sizeof(b) / sizeof(int);
    printf("%f\n", fndMdianSrtdArr(a, asize, b, bsize));
}
