

#include "shell.h"

/**
 * hsh - the manin function in shell loop
 * @info: the parameters.
 * @argumentVector: the vector
 *
 * Return: 0 on success
 */
int hsh(info_t *info, char **argumentVector)
{
	ssize_t r = 0;
	int builtin_return = 0;

	while (r != -1 && builtin_return != -2)
	{
		clear_info(info);
		if (interactive(info))
		{
			_puts("$ ");
		}

		_eputchar(BUF_FLUSH);
		r = get_input(info);

		if (r != -1)
		{
			set_info(info, argumentVector);
			builtin_return = find_builtin(info);
			if (builtin_return == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');

		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);

	if (!interactive(info) && info->status)
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
