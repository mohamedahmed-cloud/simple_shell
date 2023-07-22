#include "shell.h"

/**
 * myHistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int myHistory(info_t *Inf)
{
	printList(Inf->history);
	return (0);
}
