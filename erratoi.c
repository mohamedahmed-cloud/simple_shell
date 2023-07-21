#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @string: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *string)
{
	int i = 0;
	unsigned long int result = 0;

	if (*string == '+')
		string++;  /* TODO: why does this make main return 255? */
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			result *= 10;
			result += (string[i] - '0');
			if (result > INT_MAX)
				return (-1);
		} else
			return (-1);
	}
	return (result);
}

