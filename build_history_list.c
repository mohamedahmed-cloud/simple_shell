#include "shell.h"


/**
 * start_history_list - adds entry to a history linked list
 * @Inf: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @line_count: the history line count, hist count
 *
 * Return: Always 0
 */
int start_history_list(info_t *Inf, char *buf, int line_count)
{
	list_t *node = NULL;

	if (Inf->history)
		node = Inf->history;
	node_adding_end(&node, buf, line_count);

	if (!Inf->history)
		Inf->history = node;
	return (0);
}
