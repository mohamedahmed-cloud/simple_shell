

#include "shell.h"

/**
 * shellLoop - the manin function in shell loop
 * @info: the parameters.
 * @argumentVector: the vector
 *
 * Return: 0 on success
 */
int shellLoop(info_t *info, char **argumentVector)
{
	ssize_t r = 0;
	int builtin_return = 0;

	while (r != -1 && builtin_return != -2)
	{
		clearInformation(info);
		if (inInteractive(info))
		{
			printStr("$ ");
		}

		_ePutChar(BUF_FLUSH);
		r = getInput(info);

		if (r != -1)
		{
			setInformation(info, argumentVector);
			builtin_return = findFunction(info);
			if (builtin_return == -1)
				findCommand(info);
		}
		else if (inInteractive(info))
			_putcharacter('\n');

		freeInformation(info, 0);
	}
	writeHistory(info);
	freeInformation(info, 1);

	if (!inInteractive(info) && info->status)
	{
		exit(info->status);
	}
	if (builtin_return == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_return);
}
