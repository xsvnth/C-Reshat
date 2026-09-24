#include <stdlib.h>
int **searchMatrix(int **matrix, int mSize, int *mColSize, int target) {
    int left = 0, right = mSize * (*mColSize) - 1;
    int i = 0, row = 0, col = 0;
    while (left <= right) {
        i = (right + left) / 2;
        row = i / (*mColSize);
        col = i % (*mColSize);
        if (matrix[row][col] == target)
            break;
        if (matrix[row][col] < target)
            left = i + 1;
        else 
            right = i - 1;
    }
    int **ret = malloc(sizeof(int*));
    ret[0] = malloc(2 * sizeof(int));
    ret[0][0] = row;
    ret[0][1] = col;
    return ret;
}
#include <stdio.h>
int main() {
    int **matrix = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
        matrix[i] = malloc(3 * sizeof(int));
    int vals[3][3] = {{1,3,5},{10,11,20},{23,34,60}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            matrix[i][j] = vals[i][j];
    }
    int col = 3;
    int **ret = searchMatrix(matrix, 3, &col, 60);
    for (int i = 0; i < 1; i++) {
        printf("[");
        for (int j = 0; j < 2; j++)
            printf("%d, ", ret[i][j]);
        printf("\b\b]");
    }
    printf("\n");
    free(ret[0]);
    free(ret);
    for (int i = 0; i < 3; i++)
        free(matrix[i]);
    free(matrix);
}
