#include "shell.h"

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

