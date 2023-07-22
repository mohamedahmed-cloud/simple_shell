#include "shell.h"

/**
 * setAlias - sets alias to string
 * @Inf: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int setAlias(info_t *Inf, char *string)
{
	char *p;

	p = searchStr(string, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unsetAlias(Inf, string));

	unsetAlias(Inf, string);
	return (node_adding_end(&(Inf->alias), string, 0) == NULL);
}
