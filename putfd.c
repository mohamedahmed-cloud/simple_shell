#include "shell.h"

/**
 * printFd - writes the character c to given fd
 * @character: The character to print
 * @FD: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int printFd(char character, int FD)
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
