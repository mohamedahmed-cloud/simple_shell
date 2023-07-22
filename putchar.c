#include "shell.h"
/**
 * printStr - print the string.
 * @string: string to print.
 *
 * Return: return void.
 */
void printStr(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_putcharacter(string[i]);
		i++;
	}
}

