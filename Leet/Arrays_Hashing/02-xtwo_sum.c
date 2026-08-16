#include <stdlib.h>
typedef struct{
    int val;
    int index;
    int used;
} Entry;
int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    int *res = malloc(sizeof(int) * 2);
    int size = numsSize * 2;
    Entry *tab = calloc(size, sizeof(Entry));
    for (int i = 0; i < numsSize; i++){
        int needed = target - nums[i];
        int h = ((needed % size)+ size) % size;
        while(tab[h].used){
            if(tab[h].val == needed){
                res[0] = tab[h].index;
                res[1] = i;
                //*returnSize = 2;
                free(tab);
                return res;
            }
            h = (h + 1) % size;
        }
        h = ((nums[i] % size) + size) % size;
        while (tab[h].used){
            if(tab[h].val == nums[i])
                break;
            h = (h + 1) % size;
        }
        tab[h].val = nums[i];
        tab[h].index = i;
        tab[h].used = 1;
    }
    free(tab);
    return NULL;
}
#include <stdio.h>
int	main(){
	int	arr[] = {1, 6, 3, 4, 5, 10};
	int	target = 11;
	int	size = sizeof(arr) / sizeof(arr[0]);
    int retsize = 2;
	int *res = twoSum(arr, size, target, &retsize);
    printf("[");
    for(int i = 0; i < 2; i++){
        printf("%d, ", res[i]);
    }
    printf("\b\b]");
	return (0);
}
