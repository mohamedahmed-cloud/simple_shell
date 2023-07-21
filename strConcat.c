#include "shell.h"

/**
 * _strcat - concatenates
 * @dest: th
 * @src: the
 *
 * Return: poin
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = *src;
	return (ret);
}
