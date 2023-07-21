#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @Inf: struct address
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *Inf)
{
	return (isatty(STDIN_FILENO) && Inf->readfd <= 2);
}
