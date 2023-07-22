#include "shell.h"
/**
 * getStartNode - return the start of linked list
 * @nodePointer: current pointer
 * @prefixPointer: next pointer.
 * @ch: the ch to compare
 *
 * Return: return node start.
 */

list_t *getStartNode(list_t *nodePointer, char *prefixPointer, char ch)
{
	char *pointer = NULL;

	while (nodePointer)
	{
		pointer = startsWith(nodePointer->str, prefixPointer);
		if (pointer && ((ch == -1) || (*pointer == ch)))
			return (nodePointer);
		nodePointer = nodePointer->next;
	}
	return (NULL);
}
