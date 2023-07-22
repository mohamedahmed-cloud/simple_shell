#include "shell.h"

/**
 * getEnvironment - returns the string array copy of our environ
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **getEnvironment(info_t *Inf)
{
	if (!Inf->environ || Inf->env_changed)
	{
		Inf->environ = listToStrings(Inf->env);
		Inf->env_changed = 0;
	}

	return (Inf->environ);
}

