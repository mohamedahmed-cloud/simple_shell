#include "shell.h"

/**
 * fillEnvList - populates env linked list
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int fillEnvList(info_t *Inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		node_adding_end(&node, environ[i], 0);
	Inf->env = node;
	return (0);
}
