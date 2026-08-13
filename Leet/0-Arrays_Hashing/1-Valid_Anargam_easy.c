#include <string.h>
#include <stdio.h>

void	anagram(char *s1, char *s2)
{
	int	c[256] = {0};
	if (strlen(s1) != strlen(s2))
		return;
	while(*s1) {
		c[(unsigned char)*s1++]++, c[(unsigned char)*s2++]--;
		for (int i = 0; i < 256; i++)
			if (c[i]) {
				printf("False\n");
				return;
			}
	}
	printf("True\n");
}

int	main(void) {
	char	str1[17], str2[17];
	printf("enter s1 & s2->");
	scanf(" %s %s", str1, str2);
	anagram(str1, str2);
	return (0);
}
