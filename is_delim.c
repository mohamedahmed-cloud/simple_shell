#include "shell.h"

/**
 * isDelim - checks if character is a delimiter
 * @character: the character to check
 * @delimiter: the delimiter string
 * Return: 1 if true, 0 if false
 */
int isDelim(char character, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter == character)
			return (1);
		delimiter++;
	}
	return (0);
}
