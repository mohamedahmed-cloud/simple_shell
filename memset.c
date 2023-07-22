#include "shell.h"

/**
 * setMemory - fills memory
 * @s: the pointer toa
 * @b: the byte t
 * @n: the amount o
 * Return: (s) a poi
 */

char *setMemory(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
