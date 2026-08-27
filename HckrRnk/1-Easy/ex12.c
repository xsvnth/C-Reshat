/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Malloc vs Calloc Demo                                                   *
*  Description:                                                                      *
*       Demonstrates the difference between malloc and calloc in C.                  *
*       - malloc allocates memory without initialization (garbage values)            *
*       - calloc allocates memory and initializes all bytes to 0                     *
*  Input:                                                                            *
*       - None (array size is fixed in code)                                         *
*  Output:                                                                           *
*       - Prints the contents of memory allocated by malloc and calloc               *
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    int* a = malloc(n * sizeof(int));
    int* b = calloc(n, sizeof(int));

    printf("malloc memory:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("calloc memory:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");

    free(a);
    free(b);
}

