#include "shell.h"
/**
 * lengthOfList - give the list of the linked list
 * @head: head pointer.
 * Return: the len of the head.
 */

size_t lengthOfList(const  list_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
