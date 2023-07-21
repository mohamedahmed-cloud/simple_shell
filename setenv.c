#include "shell.h"

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @value: the string env var value
 * @var: the string env var property
 *  Return: Always 0
 */
int _setenv(info_t *Inf, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = Inf->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buffer;
			Inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(Inf->env), buffer, 0);
	free(buffer);
	Inf->env_changed = 1;
	return (0);
}
