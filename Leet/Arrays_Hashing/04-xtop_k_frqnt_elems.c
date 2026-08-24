#include <stdio.h>
#include <stdlib.h>
int *top_k(int *nums, int size, int k, int *retsize) {
    int OFFSET = 10000;
    int count[20001] = {0};
    int used[20001] = {0};
    int *res = malloc(k * sizeof(int));

    for (int i = 0; i < size; i++)
        count[nums[i] + OFFSET]++;

    for (int picked = 0; picked < k; picked++) {
        int best = -1;
        for (int val = 0; val < 20001; val++) {
            if (!used[val] && (best == -1 || count[val] > count[best]))
                best = val;
        }
        used[best] = 1;
        res[picked] = best - OFFSET;
    }

    *retsize = k;
    return res;
}
int	main(){
	int r[] = {1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 1};
	int size = sizeof(r) / sizeof(r[0]);
    int ret, *res = top_k(r, size, 2, &ret);
    printf("[");
    for(int i = 0; i < ret; i++)
        printf("%d, ", res[i]);
    printf("\b\b]\n");
    return(0);
}
