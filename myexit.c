#include "shell.h"


/**
 * myExit - exits the shell
 * @Inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if Info.argv[0] != "exit"
 */
int myExit(info_t *Inf)
{
	int checkexit;

	if (Inf->argv[1])
	{
		checkexit = _errfsti(Inf->argv[1]);
		if (checkexit == -1)
		{
			Inf->status = 2;
			printError(Inf, "Illegal number: ");
			_ePut(Inf->argv[1]);
			_ePutChar('\n');
			return (1);
		}
		Inf->err_num = _errfsti(Inf->argv[1]);
		return (-2);
	}
	Inf->err_num = -1;
	return (-2);
}
