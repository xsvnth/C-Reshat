/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Recursive Sequence                                                      *
*  Description: Computes the nth term of a sequence where each term is the sum of    *
*               the previous three terms, given the first three terms a, b, c.       *
*  Input:                                                                            *
*       - Four integers: n (term to find), a, b, c (first three terms)               *
*  Output:                                                                           *
*       - The nth term of the sequence                                               *
*************************************************************************************/

#include <stdio.h>

int find_nth_term(int n, int a, int b, int c) {
    if (n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;
    return find_nth_term(n-1, a, b, c)
	    + find_nth_term(n-2, a, b, c)
	    + find_nth_term(n-3, a, b, c);
}

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%d\n", find_nth_term(n, a, b, c));
}

