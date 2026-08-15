#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*encode(char **list, int size)
{
	int	i;
	int total = 0;
	for (i = 0; i < size; i++)
		total += strlen(list[i]) + 10;
	char *res = malloc(total + 1);
	char *p = res;
	for (i = 0; i < size; i++)	
		p += sprintf(p, "%zu#%s", strlen(list[i]), list[i]);
	return (res);
}

char	**decode(char *s, int *returnSize)
{
	char **res = malloc(100 * sizeof(char *));
	int i = 0, k = 0;
	while (s[i])
	{
		int len = 0;
		while (s[i] != '#')
			len = len * 10 + (s[i++] - '0');
		i++; // skip '#'
		res[k] = strndup(s + i, len);
		i += len;
		k++;
	}
	*returnSize = k;
	return (res);
}

int	main()
{
	char *list[] = {"hello", "world", "test123"};
	int size = 3;
	char *encoded = encode(list, size);
	printf("Encoded: %s\n", encoded);
	int n;
	char **decoded = decode(encoded, &n);
	printf("Decoded: [");
	for (int i = 0; i < n; i++)
		printf("\"%s\", ", decoded[i]);
	printf("\b\b]\n");
	for (int i = 0; i < n; i++)
		free(decoded[i]);
	free(decoded);
	free(encoded);
	return 0;
}
