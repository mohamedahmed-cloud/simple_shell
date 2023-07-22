#include "shell.h"

/**
 * printDecimal - function prints a decimal (integer) number (base 10)
 * @FD: the filedescriptor to write to
 * @input: the input
 *
 * Return: number of characters printed
 */
int printDecimal(int input, int FD)
{
	int (*__putchar)(char) = _putcharacter;
	int i, count = 0;
	unsigned int _abs_, current;

	if (FD == STDERR_FILENO)
		__putchar = _ePutChar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	} else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
