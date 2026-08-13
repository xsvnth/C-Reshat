/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Maximum of Four Numbers                                                 *
*  Description: Reads four integers from input and prints the maximum of them.       *
*  Input:                                                                            *
*       - Four integers                                                              *
*  Output:                                                                           *
*       - The largest of the four integers                                           *
*************************************************************************************/


#include <stdio.h>

int	 max_of_four(int a, int b, int c, int d)
{
	int	max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d\n", ans);
    
    return 0;
}
