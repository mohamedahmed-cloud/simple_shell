#include "shell.h"

/**
 * pathFinder - find the path of command line
 * @info: the current info
 * @full_path_str: the str path
 * @command: ------------------
 *
 * Return: return the full path
 */

char *pathFinder(info_t *info, char *full_path_str, char *command)
{
	int i = 0, curr_position = 0;
	char *path;

	if (!full_path_str)
		return (NULL);

	if ((_strLen(command) > 2) && startsWith(command, "./"))
	{
		if (isCmd(info, command))
			return (command);
	}


	while (1)
	{
		if (!full_path_str[i] || full_path_str[i] == ':')
		{
			path = debugChar(full_path_str, curr_position, i);
			if (!*path)
			{
				strConcat(path, command);
			}
			else
			{
				strConcat(path, "/");
				strConcat(path, command);
			}

			if (isCmd(info, path))
			{
				return (path);
				}
			if (!full_path_str[i])
				break;
			curr_position = i;
		}
		i++;
	}
	return (NULL);
}
