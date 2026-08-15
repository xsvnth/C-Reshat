#include <stdio.h>

void	anagram_grp(char	**r, int	size)
{
	int	used[256] = {0};

	printf("[");
	for (int i = 0; i < size; i++) {
		if (used[i])
			continue;

		int x[256] = {0};

		for (int k = 0; r[i][k]; k++)
			x[(unsigned char)r[i][k]]++;

		printf("[\"%s", r[i]);
		used[i] = 1;

		for (int j = i + 1; j < size; j++) {
			if (used[j])
				continue;
	
			int	y[256] = {0};
			for (int k = 0; r[j][k]; k++)
				y[(unsigned char)r[j][k]]++;
			
			int	same = 1;
			for (int t = 0; t < 256; t++) {
				if (x[t] != y[t]) {
					same = 0;
					break;
				}
			}
	
			if (same) {
				printf(",%s" , r[j]);
				used[j] = 1;
			}
		}
		
		printf("\"], ");
	}
	printf("\b\b]\n");
}
	
int main()
{
    char *arr[] = {"hat", "act","pots","tops","cat","stop"};
    anagram_grp(arr, 6);
    return 0;
}
