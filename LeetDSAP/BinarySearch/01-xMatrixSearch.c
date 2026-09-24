int searchMatrix(int **matrix, int mSize, int* colSize, int target) {
    int left = 0;
    int right = mSize * (*colSize) - 1;
    while (left <= right) {
        int i = (left + right) / 2;
        int row = i / (*colSize);
        int col = i % (*colSize);
        if (matrix[row][col] == target)
            return 1;
        if (matrix[row][col] < target)
            left = i + 1;
        else
            right = i - 1;
    }
    return 0;
}
#include <stdio.h>
int main() {
    int *matrix[] = {(int []){1, 3, 5}, 
                    (int []){10, 11, 20}, 
                    (int []){23, 34, 60}};
    int col = 3;
    printf("%d\n", searchMatrix(matrix, 3, &col, 60));
}
