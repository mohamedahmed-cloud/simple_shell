#include "shell.h"

/**
 * _mySetEnv - Initialize a new environment variable,
 *             or modify an existing one
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @value: the string env var value
 * @var: the string env var property
 *  Return: Always 0
 */
int _mySetEnv(info_t *Inf, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buffer = malloc(_strLen(var) + _strLen(value) + 2);
	if (!buffer)
		return (1);
	_strCopy(buffer, var);
	strConcat(buffer, "=");
	strConcat(buffer, value);
	node = Inf->env;
	while (node)
	{
		p = startsWith(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buffer;
			Inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	node_adding_end(&(Inf->env), buffer, 0);
	free(buffer);
	Inf->env_changed = 1;
	return (0);
}
