#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *Inf)
{
	print_list(Inf->history);
	return (0);
}

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
	ret = delete_node_at_index(&(Inf->alias),
		get_node_index(Inf->alias, node_starts_with(Inf->alias, string, -1)));
	*p = c;
	return (ret);
}

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

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *Inf)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (Inf->argc == 1)
	{
		node = Inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; Inf->argv[i]; i++)
	{
		p = _strchr(Inf->argv[i], '=');
		if (p)
			set_alias(Inf, Inf->argv[i]);
		else
			print_alias(node_starts_with(Inf->alias, Inf->argv[i], '='));
	}

	return (0);
}
