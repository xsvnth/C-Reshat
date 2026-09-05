int *min(int *a, int *b){
    if (*a <= *b)
        return a;
    return b;
}

int TrapRainWater(int *height, int hSize){
    int n = 0;
    for (int i = 1; i < hSize - 1; i++){
        int leftmax = 0, rightmax = 0;
        for(int j = 0; j < i; j++){
            if (leftmax < height[j])
                leftmax = height[j];
        }
        for(int j = i + 1; j < hSize; j++){
            if (rightmax < height[j])
                rightmax = height[j];
        }
        int water = *min(&leftmax, &rightmax) - height[i];
        n += water;
    }
    return n;
}
#include <stdio.h>
int main(){
    int tops[] = {4, 2, 0, 3, 2, 5};
    int size = sizeof(tops) / sizeof(int);
    printf("%d\n", TrapRainWater(tops, size));
}
