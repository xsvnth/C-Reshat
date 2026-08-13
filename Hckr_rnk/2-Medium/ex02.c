/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   25-Nov-2025                                                                      *
*  Program: Count Digits in a String                                                        *
*  Description:                                                                             *
*       Reads a string containing letters and digits.                                       *
*       Counts the occurrences of each digit from 0 to 9.                                   *
*       Prints the counts in order from 0 to 9, separated by spaces.                        *
*  Input:                                                                                   *
*       - A single string containing letters and digits                                     *
*  Output:                                                                                  *
*       - Ten integers representing the count of each digit from 0 to 9                     *
********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[1000];
    int count[10] = {0};

    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            count[s[i] - '0']++;
        }
    }

    for(int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}

