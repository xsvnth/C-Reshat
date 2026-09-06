int trap(int* height, int heightSize){
    int *left = height, *right = height + heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    while (left < right){
        if (*left < *right){
            if (*left >= leftMax)
                leftMax = *left;
            else
                water += leftMax - *left;
            left++;
        }
        else{
            if (*right >= rightMax)
                rightMax = *right;
            else
                water += rightMax - *right;
            right--;
        }
    }
    return water;
}
#include <stdio.h>
int main(){
    int height[] = {6, 2, 0, 3, 7, 5};
    //int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(height) / sizeof(int);
    printf("%d\n", trap(height, size));
}
