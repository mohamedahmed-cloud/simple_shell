#include "shell.h"

/**
 * _putfd - writes the character c to given fd
 * @character: The character to print
 * @FD: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char character, int FD)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(FD, buffer, i);
		i = 0;
	}
	if (character != BUF_FLUSH)
		buffer[i++] = character;
	return (1);
}

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

/**
 * _eputchar - writes the character c to stderr
 * @character: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char character)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (character != BUF_FLUSH)
		buf[i++] = character;
	return (1);
}

/**
 * _eputs - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_eputchar(string[i]);
		i++;
	}
}
