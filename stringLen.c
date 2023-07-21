#include "shell.h"

/**
 * _strlen - give me string lenght
 * @string: the string needed to give me lenght
 *
 * Return: lenght of string.
 */

int _strlen(char *string)
{
	int i = 0;

	if (!string)
	{
		return (0);
	}

	while (*string++)
	{
		i++;
	}

	return (i);
}
