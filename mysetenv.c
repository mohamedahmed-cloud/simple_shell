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
