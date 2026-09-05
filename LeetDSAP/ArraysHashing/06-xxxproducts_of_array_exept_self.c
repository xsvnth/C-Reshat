#include<stdio.h>

void	x(int *r, int size)
{
	printf("[");
	for (int i = 0; i < size; i++) {
		int x = 1;
		for (int j = 0; j < size; j++)
			if (j != i)
				x *= r[j];
		printf("%d, ", x);
	}
	printf("\b\b]\n");
	return;
}

int	main()
{
	int	r[] = { 1, 2, 4, 6};
	int	size = sizeof(r)/sizeof(r[0]);
	x(r, size);
	return(0);
}
