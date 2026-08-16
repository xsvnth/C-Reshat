#include <stdio.h>

int	x(int r[10])
{
	int x[50] = {0};
	int max = 0;
	for (int i = 0; i < 10; i++)
		x[r[i]] = 1;
	for (int i = 0; i < 10; i++) {
		int n = r[i];
		if(!x[n - 1]) {
			int len = 1;
			while (x[n + 1]) {
				n++;
				len++;
			}
			if (len > max)
				max = len;
		}
	}
	return (max);
}

int	main()
{
	int r[10] = { 2, 20, 4, 10, 3, 4, 5};
	int y = x(r);
	printf("%d\n", y);
	return(0);
}
