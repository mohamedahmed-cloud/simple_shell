#include "shell.h"

/**
 * _mycd - changes the current directory of the process
 * @Info: Structure containing potential arguments. Used to maintain
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
	}
	else if (_strcmp(Inf->argv[1], "-") == 0)
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
	}
	else
		chdir_ret = chdir(Inf->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(Inf, "can't cd to ");
		_eputs(Inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(Inf, "OLDPWD", _getenv(Inf, "PWD="));
		_setenv(Inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}




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
/**
 * _myhelp - changes the current directory of the process
 * @Info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *Inf)
{
	char **args_array;

	args_array = Inf->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*args_array);
	return (0);
}
