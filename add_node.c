#include "shell.h"

/**
 * node_adding - adds a node to the start of the list
 * @head: address of pointer to head node
 * @number: node index used by history
 * @string: string field of node
 *
 * Return: size of list
 */
list_t *node_adding(list_t **head, const char *string, int number)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	setMemory((void *) new_head, 0, sizeof(list_t));
	new_head->num = number;
	if (string)
	{
		new_head->str = _strdup(string);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
