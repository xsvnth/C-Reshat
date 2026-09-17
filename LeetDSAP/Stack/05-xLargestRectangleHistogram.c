#include "Stack.h"

int LargestRectangleHistogram(int *heights, int hSize) {
    t_Stack *obj = StackCreate();
    int maxArea = 0, width = 0;
    for (int i = 0; i <= hSize; i++){
        int current = (i == hSize) ? 0 : heights[i];
        while (!isEmpty(obj) && current < heights[Top(obj)]) { 
            int popped = Top(obj);
            Pop(obj);
            if (isEmpty(obj))
                width = i;
            else 
                width = i - Top(obj) - 1;
            int area = heights[popped] * width;
            if (maxArea < area)
                maxArea = area;
        }
        Push(obj, i);
    }
    return (maxArea);
}
#include <stdio.h>
int main(){
    int hghts[] = {2, 1, 5, 6, 2, 3};
    int hsize = sizeof(hghts) / sizeof(int);
    printf("%d\n", LargestRectangleHistogram(hghts, hsize));
}
