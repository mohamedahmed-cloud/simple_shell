#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *Inf)
{
	return (isatty(STDIN_FILENO) && Inf->readfd <= 2);
}
/**
 * _atoi - converts a string to an integer
 * @string: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *string)
{
	int i, s = 1;
	unsigned int result = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '-')
			s *= -1;

		if (string[i] >= '0' && string[i] <= '9')
		{
			result = (result * 10) + (string[i] - '0');
		}
	}

	return (s * result);
}

/**
 * is_delim - checks if character is a delimiter
 * @character: the character to check
 * @delimiter: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char character, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter == character)
			return (1);
		delimiter++;
	}
	return (0);
}

