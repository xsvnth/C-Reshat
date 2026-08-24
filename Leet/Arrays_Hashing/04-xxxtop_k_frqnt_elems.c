#include <stdlib.h>
int *topk(int *nums, int size, int k, int *retsize){
    int *res = malloc(sizeof(int) * k);
    int offset = 10000;
    int used[20001] = {0};
    int sbuf[20001] = {0};
    for (int i = 0; i < size; i++)
        sbuf[offset + nums[i]]++;
    for (int picked = 0; picked < k; picked++){
        int best = -1;
        for (int val = 0; val < 20001; val++){
            if (!used[val] && (best == -1 || sbuf[val] > sbuf[best]))
                best = val;
        }
        used[best] = 1;
        res[picked] = best - offset;
    }
    *retsize = k;
    return res;
}
#include <stdio.h>
int main(){
    int nums[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 7, 9, 4, 3};
    int size = sizeof(nums) / sizeof(int);
    int k = 3;
    int retsize;
    int *res = topk(nums, size, k, &retsize);
    printf("[");
    for(int i = 0; i < retsize; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");

}
