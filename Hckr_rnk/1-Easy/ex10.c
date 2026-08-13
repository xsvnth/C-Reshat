/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Number Range to Words or Parity                                         *
*  Description: Reads two integers a and b and prints each number from a to b.       *
*               - If the number is 1–9, print its English word.                      *
*               - If the number > 9, print "even" or "odd" based on parity.          *
*  Input:                                                                            *
*       - Two integers a and b                                                       *
*  Output:                                                                           *
*       - Each number converted as described, one per line                           *
*************************************************************************************/

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d\n%d", &a, &b);
    char *r[] = {"one", "two", "three", "four",
	    "five", "six", "seven", "eight", "nine"};
    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9)
            printf("%s\n", r[i - 1]);
        else
            printf("%s\n", i % 2 == 0 ? "even" : "odd");
    }
    return 0;
}
