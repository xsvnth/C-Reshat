int *finder(int r[4][4], int rows, int cols){
    int left = 0, right = cols - 1;
    while (left < right){
        int mid = left + (right - left) / 2;
        int row = 0;
        for (int i = 1; i < rows; i++){
            if (r[i][mid] > r[row][mid])
                row = i;
        }
        if (r[row][mid] < r[row][mid + 1])
            left = mid + 1;
        else 
            right = mid;
    }
    int row = 0;
    for (int i = 1; i < rows; i++){
        if(r[i][left] > r[row][left])
            row = i;
    }
    return &r[row][left];
}
#include <stdio.h>
int main(){
    int r[4][4] = {
        {1, 6, 3, 4},
        {0, 12, 2, 3},
        {9, 3, 5, 9},
        {8, 7, 6, 44}
    };
    int *peak = finder(r, 4, 4);
    printf("%d\n", *peak);
    return 0;
}
