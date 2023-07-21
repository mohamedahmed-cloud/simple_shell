#include "shell.h"

/**
 **_strncat - concatenates two strings
 *@destination: the first string
 *@number: the number of bytes to be maximally used
 *@source: the second string
 *Return: the concatenated string
 */
char *_strncat(char *destination, char *source, int number)
{
	int i, j;
	char *ptr = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < number)
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	if (j < number)
		destination[i] = '\0';
	return (ptr);
}
