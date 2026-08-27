/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Marks Summation by Gender                                               *
*  Description: Reads n marks and a gender character ('b' or 'g') and sums the marks *
*               for that gender. Assumes alternating order in input (boy, girl, ...).*
*  Input:                                                                            *
*       - An integer n                                                               *
*       - n integers (marks)                                                         *
*       - A character g ('b' or 'g')                                                 *
*  Output:                                                                           *
*       - Sum of marks for the specified gender                                      *
*************************************************************************************/

#include <stdio.h>

int marks_summation(int* marks, int n, char gender) {
    int sum = 0;
    for(int i = (gender=='b'?0:1); i < n; i += 2)
        sum += marks[i];
    return sum;
}

int main() {
    int n;
    char g;

    printf("dekel n =");

    scanf("dekel n = %d", &n);
    int marks[n];
    for(int i=0;i<n;i++)
	    scanf("dekhel n9at = %d",&marks[i]);
    scanf("sex = %c",&g);
    printf("%d\n", marks_summation(marks,n,g));
}
