#include "shell.h"

/**
 * find_builtin - return the function.
 * @info: variable passed to function.
 *
 * Return: -return the value.
 */


int find_builtin(info_t *info)
{
	int i;
	int built_in_return = -1;


	builtin_table builtintbl[] = {
			{"exit",     _myexit},
			{"env",      _myenv},
			{"help",     _myhelp},
			{"history",  _myhistory},
			{"setenv",   _mysetenv},
			{"unsetenv", _myunsetenv},
			{"cd",       _mycd},
			{"alias",    _myalias},
			{NULL, NULL}
	};


	for (i = 0; builtintbl[i].type; i++)
	{
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_return = builtintbl[i].func(info);
			break;
		}
	}

	return (built_in_return);
}
