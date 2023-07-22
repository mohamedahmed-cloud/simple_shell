#include "shell.h"

/**
 * fS - frees a string
 * @pointer: string
 */
void fS(char **pointer)
{
	char **a = pointer;

	if (!pointer)
		return;
	while (*pointer)
		free(*pointer++);
	free(a);
}
