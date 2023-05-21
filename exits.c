#include "shell.h"

/**
 **_strchr - locates a character in a string
 *@character: the character to look for
 *@string: the string to be parsed
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *string, char character)
{
	do {
		if (*string == character)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}

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

/**
 **_strncpy - copies a string
 *@destination: the destination string to be copied to
 *@number: the number of characters to be copied
 *@source: the source string
 *Return: the concatenated string
 */
char *_strncpy(char *destination, char *source, int number)
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
