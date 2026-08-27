/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Sum of Digits                                                           *
*  Description: Reads an integer n and computes the sum of its digits.               *
*  Input:                                                                            *
*       - A single integer n                                                         *
*  Output:                                                                           *
*       - Sum of the digits of n                                                     *
*************************************************************************************/


#include <stdio.h>
int main(){int n,s=0;scanf("%d",&n);
	while(n){s+=n%10;n/=10;}printf("%d\n",s);}

