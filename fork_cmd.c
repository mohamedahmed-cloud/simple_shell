#include "shell.h"

/**
 * fork_cmd - to fork the execution 
 * @info: the parameter
 *
 * Return: don't return any thing.
 */

void fork_cmd(info_t *information)
{

	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		perror("Error:");
		return;
	}

	if (child_process == 0)
	{
		if (execve(information->path, information->argv, get_environ(information)) == -1)
		{
			free_info(information, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(information->status));
		if (WIFEXITED(information->status))
		{
			information->status = WEXITSTATUS(information->status);
			if (information->status == 126)
			{
				print_error(information, "Permission denied\n");
			}
		}
	}
}

