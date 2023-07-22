#include "shell.h"

/**
 * chain_check - checks if the are the chain or not.
 * @info: the parameter passed
 * @buffer: the char buffer
 * @p: address passed
 * @i: starting point
 * @length: our length.
 *
 * Return: don't return any thing.
 */
void chain_check(info_t *info, char *buffer,
				 size_t *p, size_t i, size_t length)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buffer[i] = 0;
			j = length;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buffer[i] = 0;
			j = length;
		}
	}

	*p = j;
}
