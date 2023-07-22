#include "shell.h"

/**
 * unsetEnv - Remove an environment variable
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 *  Return: 1 on delete, 0 otherwise
 */
int unsetEnv(info_t *Inf, char *var)
{
	list_t *node = Inf->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = startsWith(node->str, var);
		if (p && *p == '=')
		{
			Inf->env_changed = deleteAtIndex(&(Inf->env), i);
			i = 0;
			node = Inf->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (Inf->env_changed);
}
