#include "shell.h"


/**
 * unsetAlias - sets alias to string
 * @Inf: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unsetAlias(info_t *Inf, char *string)
{
	char *p, c;
	int ret;

	p = searchStr(string, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = deleteAtIndex(&(Inf->alias), searchIndex(Inf->alias,
												   getStartNode(
														   Inf->alias,
														   string,
														   -1)));
	*p = c;
	return (ret);
}
