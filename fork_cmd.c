#include "shell.h"

/**
 * forkCommand - to fork the execution
 * @information: the parameter
 *
 * Return: don't return any thing.
 */

void forkCommand(info_t *information)
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
		if (execve(information->path, information->argv,
				   getEnvironment(information)) == -1)
		{
			freeInformation(information, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	} else
	{
		wait(&(information->status));
		if (WIFEXITED(information->status))
		{
			information->status = WEXITSTATUS(information->status);
			if (information->status == 126)
			{
				printError(information, "Permission denied\n");
			}
		}
	}
}

