#include "shell.h"
/**
 * _puts - print the string.
 * @string: string to print.
 *
 * Return: return void.
 */
void _puts(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}

