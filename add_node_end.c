#include "shell.h"


/**
 * node_adding_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @number: node index used by history
 * @string: str field of node
 *
 * Return: size of list
 */
list_t *node_adding_end(list_t **head, const char *string, int number)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	setMemory((void *) new_node, 0, sizeof(list_t));
	new_node->num = number;
	if (string)
	{
		new_node->str = _strdup(string);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	} else
		*head = new_node;
	
	return (new_node);
}
