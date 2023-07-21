#include "shell.h"

/**
 * _unsetenv - Remove an environment variable
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 *  Return: 1 on delete, 0 otherwise
 */
int _unsetenv(info_t *Inf, char *var)
{
	list_t *node = Inf->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			Inf->env_changed = delete_node_at_index(&(Inf->env), i);
			i = 0;
			node = Inf->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (Inf->env_changed);
}
