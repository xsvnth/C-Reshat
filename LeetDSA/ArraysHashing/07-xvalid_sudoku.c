int valid_soduko(int **soduko, int size, int *csize){
    int row[9][10] = {0};
    int col[9][10] = {0};
    int box[9][10] = {0};
    for (int i = 0; i < size; i++){
        for (int j = 0; j < *csize; j++){
            int num = soduko[i][j];
            int b = (i / 3) * 3 + (j / 3);
            row[i][num]++;
            col[j][num]++;
            box[b][num]++;
            if(row[i][num] != 1 
                    || col[j][num] != 1
                    || box[b][num] != 1)
                return 0;
        }
    }
    return 1;
}
#include <stdio.h>
int main(){
    int r1[] = {5, 3, 4, 6, 7, 8, 9, 1, 2},
        r2[] = {6, 7, 2, 1, 9, 5, 3, 4, 8},
        r3[] = {1, 9, 8, 3, 4, 2, 5, 6, 7},
        r4[] = {8, 5, 9, 7, 6, 1, 4, 2, 3},
        r5[] = {4, 2, 6, 8, 5, 3, 7, 9, 1},
        r6[] = {7, 1, 3, 9, 2, 4, 8, 5, 6},
        r7[] = {9, 6, 1, 5, 3, 7, 2, 8, 4},
        r8[] = {2, 8, 7, 4, 1, 9, 6, 3, 5},
        r9[] = {3, 4, 5, 2, 8, 6, 1, 7, 9};

    int *soduko[] = {
        r1, r2, r3,
        r4, r5, r6,
        r7, r8, r9
    };
    int size = 9;
    int colsize = 9;
    printf("%d\n", valid_soduko(soduko, size, &colsize));
}
