/*************************************************************************************
*  Author: @7meTh                                                                    *
*  Date:   10-Nov-2025                                                               *
*  Exercise: Read Char, String, and Sentence                                         *
*  Description: Reads a single character, a string, and a sentence from user input,  *
*               then prints them each on a new line.                                 *
*  Input:                                                                            *
*       - A single character                                                         *
*       - A string (max 99 characters)                                               *
*       - A sentence (max 99 characters)                                             *
*  Output: The character, string, and sentence printed each on its own line.         *
*************************************************************************************/


#include<stdio.h>
#include<string.h>

int main()
{
	char	ch;
	char	s[100], sen[100];

	scanf("%c\n", &ch);
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = 0;
	fgets(sen, sizeof(sen), stdin);
	sen[strcspn(sen, "\n")] = 0;
	
	printf("%c\n", ch);
	printf("%s\n", s);
	printf("%s\n", sen);

	return(0);
}
