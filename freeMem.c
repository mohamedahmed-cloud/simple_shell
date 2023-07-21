#include "shell.h"

/**
 * ffree - frees a stri
 * @pointer: string
 */
void ffree(char **pointer)
{
	char **a = pointer;

	if (!pointer)
		return;
	while (*pointer)
		free(*pointer++);
	free(a);
}
