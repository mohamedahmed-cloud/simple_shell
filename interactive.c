#include "shell.h"

/**
 * inInteractive - returns true if shell is in inInteractive mode
 * @Inf: struct address
 * Return: 1 if in inInteractive mode, 0 otherwise
 */
int inInteractive(info_t *Inf)
{
	return (isatty(STDIN_FILENO) && Inf->readfd <= 2);
}
