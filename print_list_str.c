#include "shell.h"


/**
 * printStringList - prints only the str element of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t printStringList(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		printStr(head->str ? head->str : "(nil)");
		printStr("\n");
		head = head->next;
		i++;
	}
	return (i);
}
