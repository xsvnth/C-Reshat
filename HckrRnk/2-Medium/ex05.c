/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Generate All Lexicographic Permutations                                 *
*  Description: Reads n strings and prints all possible permutations in lexicographic*
*               order. Uses the standard "next permutation" algorithm.               *
*  Input:                                                                            *
*       - An integer n                                                               *
*       - n strings (each max 10 characters)                                         *
*  Output:                                                                           *
*       - Each permutation printed on a separate line, strings separated by spaces   *
*************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) { char *t = *a; *a = *b; *b = t; }

int next_permutation(char **s, int n) {
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) i--;
    if (i < 0) return 0;
    int j = n - 1;
    while (strcmp(s[j], s[i]) <= 0) j--;
    swap(&s[i], &s[j]);
    for (int l = i + 1, r = n - 1; l < r; l++, r--) swap(&s[l], &s[r]);
    return 1;
}

int main() {
    int n; scanf("%d", &n);
    char **s = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        s[i] = malloc(11);
        scanf("%s", s[i]);
    }

    do {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(s, n));

    for (int i = 0; i < n; i++) free(s[i]);
    free(s);
}

