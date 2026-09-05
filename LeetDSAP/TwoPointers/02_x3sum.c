#include <stdlib.h>
#include <stdio.h>

int qcmp(const void *a, const void *b){
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int **threeSum(int *nums, int nSize,int *rSize, int **ColSizes){
    int capacity = 1;
    int **res = malloc(sizeof(int *) * capacity);
    *ColSizes = malloc(sizeof(int) * capacity);

    qsort(nums, nSize, sizeof(int), qcmp);

    int i = 0;
    for (int *p1 = nums; p1 < nums + nSize - 2; p1++){
        if (p1 > nums && *p1 == *(p1 - 1))
            continue;

        int *p2 = p1 + 1;
        int *p3 = nums + nSize - 1;

        while (p2 < p3){
            int sum = *p1 + *p2 + *p3;

            if (!sum){
                if (i == capacity){
                    capacity *= 2;

                    res = realloc(res, sizeof(int *) * capacity);
                    *ColSizes = realloc(*ColSizes, sizeof(int) * capacity);
                }

                res[i] = malloc(sizeof(int) * 3);
                
                res[i][0] = *p1;
                res[i][1] = *p2;
                res[i][2] = *p3;

                (*ColSizes)[i] = 3;
                i++;

                while (p2 < p3 && *p2 == *(p2 + 1))
                    p2++;

                while (p2 < p3 && *p3 == *(p3 - 1))
                    p3--;

                p2++;
                p3--;
            }
            else if (sum < 0)
                p2++;
            else
                p3--;
        }
    }

    *rSize = i;
    return res;
}

int main(){
    int nums[] = {9, 2, -4, 5, 0, -2, 1, -5, 6};
    int nsize = sizeof(nums) / sizeof(int);
    int rsize;
    int *csize;
    int **res = threeSum(nums, nsize, &rsize, &csize);
    printf("[");
    for (int i = 0; i < rsize; i++){
        printf("[");
        for (int j = 0; j < (csize)[i]; j++)
            printf("%d, ", res[i][j]);
        printf("\b\b]");
    }
    printf("]\n");
}
