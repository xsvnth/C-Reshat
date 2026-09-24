#include <limits.h>
double fndMdianSortdArr(int *nums1, int n1Size, int *nums2, int n2Size) {
    if (n1Size > n2Size) {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;

        int tmpSize = n1Size;
        n1Size = n2Size;
        n2Size = tmpSize;
    }
    int left = 0, right = n1Size;
    while (left <= right) {
        int partitionA = left + (right - left) / 2;
        int leftA, rightA;
        if (partitionA == 0)
            leftA = INT_MIN;
        else 
            leftA = nums1[partitionA - 1];
        if (partitionA == n1Size)
            rightA = INT_MAX;
        else 
            rightA = nums1[partitionA];
        int partitionB = (n1Size + n2Size + 1) / 2 - partitionA;
        int leftB, rightB;
        if (partitionB == 0)
            leftB = INT_MIN;
        else 
            leftB = nums2[partitionB - 1];
        if (partitionB == n2Size)
            rightB = INT_MAX;
        else 
            rightB = nums2[partitionB];
        if (leftA <= rightB && leftB <= rightA) {
            int maxLeft = leftA > leftB ? leftA : leftB;
            int minRight = rightA < rightB ? rightA : rightB;
            if ((n1Size + n2Size) % 2)
                return (double)maxLeft;
            return ((double)maxLeft + minRight) / 2.0;
        }
        else if (leftA > rightB)
            right = partitionA - 1;
        else 
            left = partitionA + 1;
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
    printf("%f\n", fndMdianSortdArr(a, asize, b, bsize));
}
