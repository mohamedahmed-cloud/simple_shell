#include "shell.h"
/**
 * _putcharacter - writes in the console
 * @ch: The character
 *
 * Return: On success 1 or 0
 */
int _putcharacter(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}
