#include "shell.h"


/**
 * _changeDirectory - changes the current directory of the process
 * @Inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _changeDirectory(info_t *Inf)
{
	char *str, *directory, buffer[1024];
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
		printStr("TODO: >>getcwd failure emsg here<<\n");
	if (!Inf->argv[1])
	{
		directory = _getEnvironment(Inf, "HOME=");
		if (!directory)
			chdir_ret = /* TODO: what should this be? */
					chdir((directory = _getEnvironment(Inf, "PWD=")) ? directory : "/");
		else
			chdir_ret = chdir(directory);
	} else if (_strComp(Inf->argv[1], "-") == 0)
	{
		if (!_getEnvironment(Inf, "OLDPWD="))
		{
			printStr(str);
			_putcharacter('\n');
			return (1);
		}
		printStr(_getEnvironment(Inf, "OLDPWD=")), _putcharacter('\n');
		chdir_ret = /* TODO: what should this be? */
				chdir((directory = _getEnvironment(Inf, "OLDPWD=")) ? directory : "/");
	} else
		chdir_ret = chdir(Inf->argv[1]);
	if (chdir_ret == -1)
	{
		printError(Inf, "can't cd to ");
		_ePut(Inf->argv[1]), _ePutChar('\n');
	} else
	{
		_mySetEnv(Inf, "OLDPWD", _getEnvironment(Inf, "PWD="));
		_mySetEnv(Inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
