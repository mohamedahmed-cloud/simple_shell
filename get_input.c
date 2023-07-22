#include "shell.h"

/**
 * getInput - gets a line minus the newline
 * @Inf: parameter struct
 *
 * Return: bytes read
 */

ssize_t getInput(info_t *Inf)
{
	static char *buffer; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(Inf->arg), *p;

	_putcharacter(BUF_FLUSH);
	r = inputBuffer(Inf, &buffer, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buffer + i; /* get pointer for return */

		chain_check(Inf, buffer, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (isChain(Inf, buffer, &j))
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
		return (_strLen(p)); /* return length of current command */
	}

	*buf_p = buffer; /* else not a chain, pass back buffer from _getLine() */
	return (r); /* return length of buffer from _getLine() */
}
