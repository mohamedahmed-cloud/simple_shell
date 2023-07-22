#include "shell.h"


/**
 * _fsti - converts a string to an integer
 * @string: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _fsti(const char *string)
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


