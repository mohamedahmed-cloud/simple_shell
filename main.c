#include "shell.h"

/**
 * main - Entery Point for the program
 * @argCount: argument counter
 * @argvector: argument vector
 *
 * Return: EXIT_SUCCESS
 */

int main(int argCount, char **argvector)
{
	info_t info_array[] = {INFO_INIT};
	int foundCommand = 2;

	asm ("mov %1, %0\n\t"
		 "add $3, %0"
			: "=r" (foundCommand)
			: "r" (foundCommand));

	if (argCount == 2)
	{
		foundCommand = open(argvector[1], O_RDONLY);
		if (foundCommand == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argvector[0]);
				_eputs(": 0: Can't open ");
				_eputs(argvector[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info_array->readfd = foundCommand;
	}
	populate_env_list(info_array);
	read_history(info_array);
	hsh(info_array, argvector);
	return (EXIT_SUCCESS);
}

