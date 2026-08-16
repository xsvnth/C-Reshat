#include<stdio.h>

void	top_k(int	*r, int size, int k)
{
	int x[10] = {0};
	int used[10] = {0};
	for (int i = 0; i < size; i++) 
		x[r[i]]++;
	printf("[");
	for (int i = 0; i < size; i++) {
		if(x[r[i]] >= k && !used[r[i]]) {
			printf("%d", r[i]);
			used[r[i]] = 1;
			if(i != size - 1)
				printf(",");
		}
	}
	printf("\b]\n");
	return;
}

int	main()
{
	int r[] = {1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 1};
	int size = sizeof(r) / sizeof(r[0]);
	top_k(r, size, 2);
	return(0);
}
