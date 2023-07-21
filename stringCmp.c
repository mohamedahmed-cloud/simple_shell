#include "shell.h"

/**
 * _strcmp - performs lexicog
 * @string1: first string
 * @string2: second string.
 *
 * Return: return the string after concation.
 */
int _strcmp(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
		{
			return (*string1 - *string2);
		}
		string1++;
		string2++;
	}
	if (*string1 == *string2)
	{
		return (0);
	}
	else
	{
		return (*string1 < *string2 ? -1 : 1);
	}
}




