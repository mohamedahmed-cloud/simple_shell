#include "shell.h"

/**
 * _ePutChar - writes the character c to stderr
 * @character: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _ePutChar(char character)
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
