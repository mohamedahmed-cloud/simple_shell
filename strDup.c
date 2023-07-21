#include "shell.h"

/**
 * _strdup - stringing dubplicate function
 * @string: string needed to duplicate
 *
 * Return: pointe
 */
char *_strdup(const char *string)
{
	int length = 0;
	char *ret;

	if (string == NULL)
	{
		return (NULL);
	}

	while (*string++)
	{
		length++;
	}

	ret = malloc(sizeof(char) * (length + 1));

	if (!ret)
	{
		return (NULL);
	}

	for (length++; length--;)
	{
		ret[length] = *--string;
	}

	return (ret);
}
