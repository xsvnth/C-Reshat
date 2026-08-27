/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Print a Square Pattern                                                  *
*  Description: Reads an integer x and prints a 2*x-1 by 2*x-1 square pattern of     *
*               numbers where the numbers decrease from the edges towards the center.*
*  Input:                                                                            *
*       - A single integer x                                                         *
*  Output:                                                                           *
*       - A 2*x-1 by 2*x-1 square of numbers forming the pattern                     *
*************************************************************************************/


#include<stdio.h>

int	main()
{
	int	x;

	scanf("%d", &x);
	for (int i = 0; i < 2 * x - 1; i++){
		for (int j = 0; j < 2 * x - 1; j++){
			int	y = i < j ? i : j;
			y = y < 2 * x - 2 - i ? y : 2 * x - 2 - i;
			y = y < 2 * x - 2 - j ? y : 2 * x - 2 - j;
			printf("%d ", x - y);
		}
		printf("\n");
	}
}
