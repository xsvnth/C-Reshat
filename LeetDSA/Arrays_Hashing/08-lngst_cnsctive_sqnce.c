#include <stdio.h>

int	x(int r[10])
{
	int x[50] = {0};
	int max = 0;
	for (int i = 0; i < 10; i++)
		x[r[i]] = 1;
	for (int i = 0; i < 10; i++) {
		int n = r[i];
		if (!x[n - 1]) {
			int len = 1;
			while (x[n + 1]) {
				len++;
				n++;
			}
			if (len > max)
				max = len;
		}
	}
	return(max);
}

int	main()
{
	int r[10] = {2, 4, 3, 8};
	int c = x(r);
	printf("%d\n", c);
}
