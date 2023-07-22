#include "shell.h"

/**
 * findFunction - return the function.
 * @info: variable passed to function.
 *
 * Return: -return the value.
 */


int findFunction(info_t *info)
{
	int i;
	int built_in_return = -1;


	builtin_table builtintbl[] = {
			{"exit",     myExit},
			{"env",      _printEnv},
			{"help",     myHelp},
			{"history",  myHistory},
			{"setenv",   mySetEnv},
			{"unsetEnv", myUnsetEnv},
			{"cd",       _changeDirectory},
			{"alias",    _myAlias},
			{NULL, NULL}
	};


	for (i = 0; builtintbl[i].type; i++)
	{
		if (_strComp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_return = builtintbl[i].func(info);
			break;
		}
	}

	return (built_in_return);
}
