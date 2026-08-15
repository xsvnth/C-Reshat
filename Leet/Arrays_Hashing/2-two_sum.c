#include <stdio.h>

void	two_sum(int	*arr, int	size, int	target)
{
	for(int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) { 
			if(arr[i] + arr[j] == target)
				printf("[ %d , %d ]\n", i, j);
		}
	}
}

int	main()
{
	int	arr[] = {1, 2, 3, 4, 5, 6};
	int	target = 4;
	int	size = sizeof(arr) / sizeof(arr[0]);

	two_sum(arr, size, target);
	return (0);
}
