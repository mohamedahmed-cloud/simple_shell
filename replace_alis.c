#include "shell.h"

/**
 * replaceAlias - replace the string.
 * @info: the parameter passed
 *
 * Return: 1 if success.
 */

int replaceAlias(info_t *info)
{
	int i;
	list_t *curr_node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		curr_node = getStartNode(info->alias, info->argv[0], '=');
		if (!curr_node)
		{
			return (0);
		}

		free(info->argv[0]);
		p = searchStr(curr_node->str, '=');

		if (!p)
		{
			return (0);
		}

		p = _strdup(p + 1);

		if (!p)
		{
			return (0);
		}

		info->argv[0] = p;
	}

	return (1);
}
