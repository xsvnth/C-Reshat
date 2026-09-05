#include <stdlib.h>
int	*two_sum(int	*arr, int resize, int	size, int	target){
    int *res = malloc(sizeof(int) * resize);
	int i, j, m, n;
    for(i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) { 
			if(arr[i] + arr[j] == target)
			    m = i, n = j;
		}
	}
    res[0] = m, res[1] = n;
    return res;
}
#include <stdio.h>
int	main(){
	int	arr[] = {1, 6, 3, 4, 5, 10};
	int	target = 11;
	int	size = sizeof(arr) / sizeof(arr[0]);
	int *res = two_sum(arr, 2, size, target);
    printf("[");
    for(int i = 0; i < 2; i++){
        printf("%d, ", res[i]);
    }
    printf("\b\b]");
	return (0);
}
