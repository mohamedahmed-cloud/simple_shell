#include "shell.h"

/**
 * replaceVariables - To replace the var in string
 * @info: paramter passed
 *
 * Return: 1 if it success.
 */
int replaceVariables(info_t *info)
{
	int i = 0;
	list_t *curr_node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strComp(info->argv[i], "$?"))
		{
			replaceString(&(info->argv[i]),
						  _strdup(numberConverting(info->status, 10, 0)));
			continue;
		}

		if (!_strComp(info->argv[i], "$$"))
		{
			replaceString(&(info->argv[i]),
						  _strdup(numberConverting(getpid(), 10, 0)));
			continue;
		}

		curr_node = getStartNode(info->env, &info->argv[i][1], '=');

		if (curr_node)
		{
			replaceString(&(info->argv[i]),
						  _strdup(searchStr(curr_node->str, '=') + 1));
			continue;
		}
		replaceString(&info->argv[i], _strdup(""));

	}

	return (0);
}


