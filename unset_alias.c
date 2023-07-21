#include "shell.h"


/**
 * unset_alias - sets alias to string
 * @Inf: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *Inf, char *string)
{
	char *p, c;
	int ret;

	p = _strchr(string, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(Inf->alias), get_node_index(Inf->alias,
															 node_starts_with(
																	 Inf->alias,
																	 string,
																	 -1)));
	*p = c;
	return (ret);
}
