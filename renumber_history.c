#include "shell.h"


/**
 * renumber_history - renumbers the history linked list after changes
 * @Inf: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *Inf)
{
	list_t *node = Inf->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (Inf->histcount = i);
}
