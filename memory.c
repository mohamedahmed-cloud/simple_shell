#include "shell.h"

/**
 * bfree - frees a pointe
 * @ptr: address of the
 *
 * Return: 1 if
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

