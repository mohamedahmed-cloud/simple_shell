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
				_ePut(argvector[0]);
				_ePut(": 0: Can't open ");
				_ePut(argvector[1]);
				_ePutChar('\n');
				_ePutChar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info_array->readfd = foundCommand;
	}
	fillEnvList(info_array);
	readHistory(info_array);
	shellLoop(info_array, argvector);
	return (EXIT_SUCCESS);
}

