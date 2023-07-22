#include "shell.h"


/**
 * _printEnv - prints the current environment
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _printEnv(info_t *Inf)
{
	printStringList(Inf->env);
	return (0);
}
