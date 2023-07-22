#include "shell.h"

/**
 * strConcat - concatenates
 * @dest: th
 * @src: the
 *
 * Return: poin
 */
char *strConcat(char *dest, char *src)
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
