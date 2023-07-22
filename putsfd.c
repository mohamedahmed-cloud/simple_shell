#include "shell.h"


/**
 * _printFd - prints an input string
 * @string: the string to be printed
 * @FD: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _printFd(char *string, int FD)
{
	int i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i += printFd(*string++, FD);
	}
	return (i);
}
