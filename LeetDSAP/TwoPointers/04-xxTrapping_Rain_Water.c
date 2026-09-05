int trap(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;

    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right){
        if (height[left] < height[right]){
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        }
        else{
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    return water;
}
#include <stdio.h>
int main(){
    //int height[] = {4, 2, 0, 3, 2, 5};
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(height) / sizeof(int);
    printf("%d\n", trap(height, size));
}
// int *min(int *a, int *b){
//      if (*a <= *b)
//          return a;
//      return b;
// }
//
// int TrapRainWater(int *height, int hSize){
//     int n = 0;
//     int *left = height, *right = height + hSize - 1;
//     for (int i = 1; i < hSize - 1; i++){
//         int leftmax = 0, rightmax = 0;
//          //for(int j = 0; j < i; j++){
//         if (leftmax < *left)
//             leftmax = *left;
//         //for(int j = i + 1; j < hSize; j++){
//         if (rightmax < *right)
//             rightmax = *right;
//         int water;
//         if (*left < leftmax)
//             water = leftmax - *left;
//         else if (*right < rightmax)
//             water = rightmax - *right;
//         n += water;
//         if (*left < *right)
//             left++;
//         else if (*left > *right)
//             right--;
//         else 
//             left++, right--;
//      }
//      return n;
// }
