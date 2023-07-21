#include "shell.h"

/**
 * get_input - gets a line minus the newline
 * @Inf: parameter struct
 *
 * Return: bytes read
 */

ssize_t get_input(info_t *Inf)
{
	static char *buffer; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(Inf->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(Inf, &buffer, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buffer + i; /* get pointer for return */

		check_chain(Inf, buffer, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(Inf, buffer, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			Inf->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buffer; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}
