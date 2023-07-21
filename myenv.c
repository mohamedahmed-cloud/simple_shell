#include "shell.h"


/**
 * _myenv - prints the current environment
 * @Inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *Inf)
{
	print_list_str(Inf->env);
	return (0);
}
