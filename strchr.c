#include "shell.h"

/**
 **_strchr - locates a character in a string
 *@character: the character to look for
 *@string: the string to be parsed
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
