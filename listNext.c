#include "shell.h"

/**
 * get_node_index - gets the index of a node
 * @headPointer: pointer to
 * @nodePointer: pointer to
 *
 * Return: index of
 */

ssize_t get_node_index(list_t *headPointer, list_t *nodePointer)
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
