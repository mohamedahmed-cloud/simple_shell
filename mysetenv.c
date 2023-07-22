#include "shell.h"

/**
 * mySetEnv - Initialize a new environment variable,
 *             or modify an existing one
 * @Inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int mySetEnv(info_t *Inf)
{
	if (Inf->argc != 3)
	{
		_ePut("Incorrect number of arguements\n");
		return (1);
	}
	if (_mySetEnv(Inf, Inf->argv[1], Inf->argv[2]))
		return (0);
	return (1);
}
