#include <stdlib.h>
int *twoPeakFinder(int **mat, int msize, int *colsize, int *rsize){
    int left = 0, right = *colsize - 1;
    while (left < right){
        int mid = left + (right - left) / 2;
        int row = 0;
        for (int i = 1; i < msize; i++) {
            if (mat[i][mid] > mat[row][mid])
                row = i;
        }
        if (mat[row][mid] < mat[row][mid + 1])
            left = mid + 1;
        else 
            right = mid;
    }
    int row = 0;
    for (int i = 1; i < msize; i++){
        if (mat[i][left] > mat[row][left])
                row = i;
    }
    int *res = malloc(2 * sizeof(int));
    *rsize = 2;
    res[0] = row, res[1] = left;
    return res;
}

#include <stdio.h>

int main(){
    int r0[] = {3, 8, 7, 6, 5}
    , r1[] = {9, 3, 22, 1, 20}
    , r2[] = {8, 4, 6, 2, 15}
    , r3[] = {7, 5, 4, 3, 14}
    , r4[] = {6, 2, 1, 0, 13};
    int *mat[] = {r0, r1, r2, r3, r4};
    int msize = 5;
    int rsize;
    int colsize = 5;
    int *res = twoPeakFinder(mat, msize, &colsize, &rsize);
    printf("[");
    for (int i = 0; i < 2; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
}
