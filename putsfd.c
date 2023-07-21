#include "shell.h"


/**
 * _putsfd - prints an input string
 * @string: the string to be printed
 * @FD: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *string, int FD)
{
	int i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i += _putfd(*string++, FD);
	}
	return (i);
}
