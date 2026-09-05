int *min(int *a, int *b){
    if (*a >= *b)
        return b;
    return a;
}
int maxArea(int *height, int heightSize){
    int *left = height, *right = height + heightSize - 1;
    int area, max = 0;
    while (left < right){
        int width = right - left;
        int *height = min(right, left);
        area = width * *height;
        if (*height == *left)
            left++;
        else if (*height == *right)
            right--;
        if (area > max)
            max = area;
    }
    return max;
}
#include <stdio.h>
int main(){
    int nums[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(nums) / sizeof(int);
    printf("%d\n", maxArea(nums, size));
}
