#include "shell.h"


/**
 * _myhelp - changes the current directory of the process
 * @Inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *Inf)
{

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

	char **args_array;

	args_array = Inf->argv;
	_puts("help call works. Function not yet implemented \n");
	return (0);
}
