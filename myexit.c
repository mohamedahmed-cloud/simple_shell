#include "shell.h"


/**
 * _myexit - exits the shell
 * @Inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if Info.argv[0] != "exit"
 */
int _myexit(info_t *Inf)
{
	int checkexit;

	if (Inf->argv[1])
	{
		checkexit = _erratoi(Inf->argv[1]);
		if (checkexit == -1)
		{
			Inf->status = 2;
			print_error(Inf, "Illegal number: ");
			_eputs(Inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		Inf->err_num = _erratoi(Inf->argv[1]);
		return (-2);
	}
	Inf->err_num = -1;
	return (-2);
}
