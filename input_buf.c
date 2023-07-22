#include <signal.h>
#include "shell.h"

/**
 * inputBuffer - buffers chained commands
 * @buffer: address of buffer
 * @Inf: parameter struct
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t inputBuffer(info_t *Inf, char **buffer, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*freePtr((void **)info->cmd_buf);*/
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getLine(Inf, buffer, &len_p);
#endif
		if (r > 0)
		{
			if ((*buffer)[r - 1] == '\n')
			{
				(*buffer)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			Inf->linecount_flag = 1;
			removeComments(*buffer);
			start_history_list(Inf, *buffer, Inf->histcount++);
			{
				*len = r;
				Inf->cmd_buf = buffer;
			}
		}
	}
	return (r);
}
