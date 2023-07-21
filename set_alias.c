#include "shell.h"

/**
 * set_alias - sets alias to string
 * @Inf: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *Inf, char *string)
{
	char *p;

	p = _strchr(string, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(Inf, string));

	unset_alias(Inf, string);
	return (add_node_end(&(Inf->alias), string, 0) == NULL);
}
