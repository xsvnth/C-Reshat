#include<stdio.h>

void	group_anagrams(char	**r, int	size) 
{
	printf("[");
	int	used[256] = {0};
	for(int i = 0; i < size; i++) {
		if (used[i]) continue;
		int x[256] = {0};
		for (int k = 0; r[i][k]; k++)
			x[(unsigned char)r[i][k]]++;
		printf("[\"%s", r[i]);
		used[i] = 1;
		for (int j = i+1; j < size; j++) {
			if(used[j]) continue;
			int y[256] = {0};
			for (int k = 0; r[j][k]; k++)
				y[(unsigned char)r[j][k]]++;
			int same = 1;
			for (int t = 0; t < 256; t++) {
				if (x[t] != y[t]) {
					same = 0;
					break;
				}
			}
			if (same ) {
				printf("\", \"%s", r[j]);
				used[j] = 1;
			}
		}
		printf("\"], ");
	}
	printf("\b\b]\n");
	return;
}

int	main()
{
	char	*r[256] = {"cat", "tac", "act", "hat"};
	group_anagrams(r, 4);
	return(0);
}
