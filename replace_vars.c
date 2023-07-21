#include "shell.h"

/**
 * replace_vars - To replace the var in string
 * @info: paramter passed
 *
 * Return: 1 if it success.
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *curr_node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
						   _strdup(convert_number(info->status, 10, 0)));
			continue;
		}

		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
						   _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}

		curr_node = node_starts_with(info->env, &info->argv[i][1], '=');

		if (curr_node)
		{
			replace_string(&(info->argv[i]),
						   _strdup(_strchr(curr_node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}

	return (0);
}


