#include "shell.h"

/**
 **searchStr - locates a character in a string
 *@character: the character to look for
 *@string: the string to be parsed
 *Return: (s) a pointer to the memory area s
 */
char *searchStr(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
