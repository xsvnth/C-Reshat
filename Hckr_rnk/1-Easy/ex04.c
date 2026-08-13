/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Update Two Numbers                                                      *
*  Description: Reads two integers, updates them as follows:                         *
*               - a = a + b                                                          *
*               - b = |b - a_old| (absolute difference)                              *
*               Then prints the updated values.                                      *
*  Input:                                                                            *
*       - Two integers a and b                                                       *
*  Output:                                                                           *
*       - Updated value of a                                                         *
*       - Updated value of b                                                         *
*************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b){
    int x = *a;
    *a = *a + *b;
    *b = abs(*b - x);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d\n", a, b);
}

