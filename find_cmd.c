#include "shell.h"
/**
 * findCommand - finds a command
 * @info: the parameter
 *
 * Return: void
 */
void findCommand(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
	{
		if (!isDelim(info->arg[i], " \t\n"))
			k++;
	}

	if (!k)
		return;

	path = pathFinder(info, _getEnvironment(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		forkCommand(info);
	}

	else
	{
	if ((inInteractive(info) || _getEnvironment(info, "PATH=") || info->argv[0][0] == '/')
		&& isCmd(info, info->argv[0]))
	{
		forkCommand(info);
	}
	else if (*(info->arg) != '\n')
	{
		info->status = 127;
		printError(info, "not found\n");
	}
}

}
