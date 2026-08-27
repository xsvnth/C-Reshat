/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Number to Word                                                          *
*  Description: Reads an integer n and prints its English word representation if n   *
*               is between 1 and 9. If n > 9, prints "Greater than 9".               *
*  Input:                                                                            *
*       - A single integer n                                                         *
*  Output:                                                                           *
*       - The English word for n (1-9) or "Greater than 9"                           *
*************************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char *R[] = {"one", "two", "three", "four",
	    "five", "six", "seven", "eight", "nine"};
    if (n >= 1 && n <= 9)
        printf("%s", R[n - 1]);
    else
        printf("Greater than 9");
    return 0;
}

