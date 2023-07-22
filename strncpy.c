
#include "shell.h"


/**
 **_strcpy - copies a string
 *@destination: the destination string to be copied to
 *@number: the number of characters to be copied
 *@source: the source string
 *Return: the concatenated string
 */
char *_strcpy(char *destination, char *source, int number)
{
	int i, j;
	char *s = destination;

	i = 0;
	while (source[i] != '\0' && i < number - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < number)
	{
		j = i;
		while (j < number)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}
