#include "shell.h"

/**
 * find_path - find the path of command line
 * @info: the current info
 * @full_path_str: the str path
 * @command: ------------------
 *
 * Return: return the full path
 */

char *find_path(info_t *info, char *full_path_str, char *command)
{
	int i = 0, curr_position = 0;
	char *path;

	if (!full_path_str)
		return (NULL);

	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (is_cmd(info, command))
			return (command);
	}


	while (1)
	{
		if (!full_path_str[i] || full_path_str[i] == ':')
		{
			path = dup_chars(full_path_str, curr_position, i);
			if (!*path)
			{
				_strcat(path, command);
			}
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}

			if (is_cmd(info, path))
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
