#include "shell.h"

/**
 * searchIndex - gets the index of a node
 * @headPointer: pointer to
 * @nodePointer: pointer to
 *
 * Return: index of
 */

ssize_t searchIndex(list_t *headPointer, list_t *nodePointer)
{
	size_t indx = 0;

	while (headPointer)
	{
		if (headPointer == nodePointer)
			return (indx);
		headPointer = headPointer->next;
		indx++;
	}
	return (-1);
}
