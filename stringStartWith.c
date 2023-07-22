#include "shell.h"

/**
 * startsWith - start with the string.
 * @string1: string
 * @string2: the subst
 *
 * Return: the address
 */

char *startsWith(const char *string1, const char *string2)
{
	while (*string2)
		if (*string2++ != *string1++)
			return (NULL);
	return ((char *) string1);
}
