/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   25-Nov-2025                                                                      *
*  Program: Reverse Array                                                                   *
*  Description:                                                                             *
*       Reads an integer N and an array of N integers from input.                           *
*       Reverses the array in-place and prints the reversed array.                          *
*  Input:                                                                                   *
*       - N : Number of elements in the array                                               *
*       - N integers : The elements of the array                                            *
*  Output:                                                                                  *
*       - The array elements in reverse order, printed on a single line                     *
********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i, temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /* Logic to reverse the array */
    for (i = 0; i < num / 2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + (num - i - 1));
        *(arr + (num - i - 1)) = temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));

    free(arr);
    return 0;
}

