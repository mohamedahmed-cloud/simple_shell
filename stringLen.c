#include "shell.h"

/**
 * _strLen - give me string lenght
 * @string: the string needed to give me lenght
 *
 * Return: lenght of string.
 */

int _strLen(char *string)
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
