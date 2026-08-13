/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Sum and Difference of Integers and Floats                               *
*  Description: Reads two integers and two floats from input, then prints:           *
*               - Sum and difference of the integers                                 *
*               - Sum and difference of the floats (1 decimal place)                 *
*  Input:                                                                            *
*       - Two integers                                                               *
*       - Two floats                                                                 *
*  Output:                                                                           *
*       - Sum and difference of integers                                             *
*       - Sum and difference of floats (formatted to 1 decimal)                      *
*************************************************************************************/


#include<math.h>
#include<stdio.h>

int main()
{
	int x, y;
	float z, w;
	
	scanf("%d%d%f%f", &x, &y, &z, &w);
	printf("%d %d\n%.1f %.1f\n", x+y, x-y, z+w, z-w);
	return 0;
}
