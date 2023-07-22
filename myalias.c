#include "shell.h"



/**
 * _myAlias - mimics the alias builtin (man alias)
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myAlias(info_t *Inf)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (Inf->argc == 1)
	{
		node = Inf->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; Inf->argv[i]; i++)
	{
		p = searchStr(Inf->argv[i], '=');
		if (p)
			setAlias(Inf, Inf->argv[i]);
		else
			printAlias(getStartNode(Inf->alias, Inf->argv[i], '='));
	}

	return (0);
}

