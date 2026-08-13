/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   25-Nov-2025                                                                      *
*  Program: Tokenize String                                                                 *
*  Description:                                                                             *
*       Reads a line of text from input.                                                    *
*       Splits the text into words separated by spaces.                                     *
*       Prints each word on a new line.                                                     *
*  Input:                                                                                   *
*       - A single line of text                                                             *
*  Output:                                                                                  *
*       - Each word from the input printed on its own line                                  *
********************************************************************************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    // Tokenize and print each word on new line
    char *token = strtok(s, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    free(s);
    return 0;
}

