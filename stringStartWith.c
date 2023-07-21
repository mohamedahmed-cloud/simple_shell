#include "shell.h"

/**
 * starts_with - start with the string.
 * @string1: string
 * @string2: the subst
 *
 * Return: the address
 */

char *starts_with(const char *string1, const char *string2)
{
	while (*string2)
		if (*string2++ != *string1++)
			return (NULL);
	return ((char *) string1);
}
