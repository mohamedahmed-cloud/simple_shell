#include "shell.h"
/**
 * listToStrings - give me list from string.
 * @headPointer: head of linked list
 *
 * Return: array of string.
 */
char **listToStrings(list_t *headPointer)
{
	list_t *node = headPointer;
	size_t i = lengthOfList(headPointer), j;
	char **strs;
	char *str;


	if (!headPointer || !i)
		return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
		return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strLen(node->str) + 1);

		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strCopy(str, node->str);
		strs[i] = str;
	}

	strs[i] = NULL;
	return (strs);
}
