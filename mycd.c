#include "shell.h"


/**
 * _mycd - changes the current directory of the process
 * @Inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *Inf)
{
	char *str, *directory, buffer[1024];
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!Inf->argv[1])
	{
		directory = _getenv(Inf, "HOME=");
		if (!directory)
			chdir_ret = /* TODO: what should this be? */
					chdir((directory = _getenv(Inf, "PWD=")) ? directory : "/");
		else
			chdir_ret = chdir(directory);
	} else if (_strcmp(Inf->argv[1], "-") == 0)
	{
		if (!_getenv(Inf, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(Inf, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
				chdir((directory = _getenv(Inf, "OLDPWD=")) ? directory : "/");
	} else
		chdir_ret = chdir(Inf->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(Inf, "can't cd to ");
		_eputs(Inf->argv[1]), _eputchar('\n');
	} else
	{
		_setenv(Inf, "OLDPWD", _getenv(Inf, "PWD="));
		_setenv(Inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
