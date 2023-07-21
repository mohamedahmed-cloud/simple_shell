#include "shell.h"

/**
 * is_chain - test if
 * @info: information
 * @buffer: buffer passed.
 * @p: address.
 *
 * Return: 1 if success.
 */

int is_chain(info_t *info, char *buffer, size_t *p)
{
	size_t j = *p;

	if (buffer[j] == '|' && buffer[j + 1] == '|')
	{
		buffer[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}

	else if (buffer[j] == '&' && buffer[j + 1] == '&')
	{
		buffer[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}

	else if (buffer[j] == ';')
	{
		buffer[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);

	*p = j;
	return (1);
}
