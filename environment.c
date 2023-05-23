#include "shell.h"





/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *Inf)
{
	if (Inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(Inf, Inf->argv[1], Inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _getenv - gets the value of an environ variable
 * @Inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *Inf, const char *name)
{
	list_t *node = Inf->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _myunsetenv - Remove an environment variable
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *Inf)
{
	int i;

	if (Inf->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= Inf->argc; i++)
		_unsetenv(Inf, Inf->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *Inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	Inf->env = node;
	return (0);
}

/**
 * _myenv - prints the current environment
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *Inf)
{
	print_list_str(Inf->env);
	return (0);
}
