/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   25-Nov-2025                                                                      *
*  Program: Sum of Array                                                                    *
*  Description:                                                                             *
*       Reads an integer N and then N integers from input.                                  *
*       Computes the sum of these N integers.                                               *
*       Prints the sum.                                                                     *
*  Input:                                                                                   *
*       - N : Number of integers                                                            *
*       - N integers : The elements to sum                                                  *
*  Output:                                                                                  *
*       - Single integer representing the sum of the input integers                         *
********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, sum = 0, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
    }

    printf("%d", sum);

    return 0;
}

