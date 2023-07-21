#include "shell.h"



/**
 * _myalias - mimics the alias builtin (man alias)
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *Inf)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (Inf->argc == 1)
	{
		node = Inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; Inf->argv[i]; i++)
	{
		p = _strchr(Inf->argv[i], '=');
		if (p)
			set_alias(Inf, Inf->argv[i]);
		else
			print_alias(node_starts_with(Inf->alias, Inf->argv[i], '='));
	}

	return (0);
}

