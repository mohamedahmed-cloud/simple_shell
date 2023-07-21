#include "shell.h"
/**
 * node_starts_with - return the start of linked list
 * @nodePointer: current pointer
 * @prefixPointer: next pointer.
 * @ch: the ch to compare
 *
 * Return: return node start.
 */

list_t *node_starts_with(list_t *nodePointer, char *prefixPointer, char ch)
{
	char *pointer = NULL;

	while (nodePointer)
	{
		pointer = starts_with(nodePointer->str, prefixPointer);
		if (pointer && ((ch == -1) || (*pointer == ch)))
			return (nodePointer);
		nodePointer = nodePointer->next;
	}
	return (NULL);
}
