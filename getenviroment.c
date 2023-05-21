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

/**
 * get_environ - returns the string array copy of our environ
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *Inf)
{
	if (!Inf->environ || Inf->env_changed)
	{
		Inf->environ = list_to_strings(Inf->env);
		Inf->env_changed = 0;
	}

	return (Inf->environ);
}



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

