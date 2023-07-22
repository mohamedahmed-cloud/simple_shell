#include "shell.h"


/**
 * _ePut - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _ePut(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_ePutChar(string[i]);
		i++;
	}
}
