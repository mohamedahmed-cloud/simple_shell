#include "shell.h"

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
