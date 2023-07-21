#include "shell.h"


/**
 * build_history_list - adds entry to a history linked list
 * @Inf: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *Inf, char *buf, int linecount)
{
	list_t *node = NULL;

	if (Inf->history)
		node = Inf->history;
	add_node_end(&node, buf, linecount);

	if (!Inf->history)
		Inf->history = node;
	return (0);
}
