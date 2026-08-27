/************************************************************
*  Author: @7meTh                                           *
*  Date:   10-Nov-2025                                      *
*  Exercise: Hello World with User Input                    *
*  Description: Prints "Hello, World!" then reads a line of *
*               text from the user and prints it back.      *
*  Input: A single line of text (max 99 characters)         *
*  Output: "Hello, World!" followed by the input text       *
************************************************************/

#include <stdio.h>
#include <string.h>

int main() 
{
    char s[100];
    printf("Hello, World!\n");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    printf("%s\n", s);
    return 0;
}

