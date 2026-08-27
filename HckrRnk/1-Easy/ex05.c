/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Bitwise Operators: Maximum Values                                       *
*  Description: Reads two integers n and k, then computes the maximum values less    *
*               than k for the following bitwise operations among all pairs (a,b):   *
*               - AND (a & b)                                                        *
*               - OR  (a | b)                                                        *
*               - XOR (a ^ b)                                                        *
*  Input:                                                                            *
*       - Two integers n and k                                                       *
*  Output:                                                                           *
*       - Maximum value of a&b < k                                                   *
*       - Maximum value of a|b < k                                                   *
*       - Maximum value of a^b < k                                                   *
*************************************************************************************/


#include <stdio.h>

void calculate_the_maximum(int n, int k) {
    int a,b,m1=0,m2=0,m3=0;
    for(a=1;a<=n;a++)
        for(b=a+1;b<=n;b++){
            if((a&b)<k && (a&b)>m1) m1=a&b;
            if((a|b)<k && (a|b)>m2) m2=a|b;
            if((a^b)<k && (a^b)>m3) m3=a^b;
        }
    printf("%d\n%d\n%d\n",m1,m2,m3);
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    calculate_the_maximum(n,k);
}

