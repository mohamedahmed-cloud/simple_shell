#include "shell.h"

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
