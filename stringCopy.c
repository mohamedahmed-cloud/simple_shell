#include "shell.h"

/**
 * _strCopy - copie
 * @destition: the destitionin
 * @source: the source
 *
 * Return: pointe
 */
char *_strCopy(char *destition, char *source)
{
	int i = 0;

	if (destition == source || source == 0)
	{
		return (destition);
	}

	while (source[i])
	{
		destition[i] = source[i];
		i++;
	}

	destition[i] = 0;

	return (destition);
}

