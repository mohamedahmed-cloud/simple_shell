#include "shell.h"

/**
 * printAlias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int printAlias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = searchStr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putcharacter(*a);
		_putcharacter('\'');
		printStr(p + 1);
		printStr("'\n");
		return (0);
	}
	return (1);
}
