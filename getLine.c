#include "shell.h"

/**
 * _getline - gets the next line of input from STDIN
 * @Inf: parameter struct
 * @length: size of preallocated ptr buffer if not NULL
 * @ptr: address of pointer to buffer, preallocated or NULL
 *
 * Return: s
 */
int _getline(info_t *Inf, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(Inf, buffer, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buffer + i, k - i);
	else
		_strncpy(new_p, buffer + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}



/**
 * get_input - gets a line minus the newline
 * @Inf: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *Inf)
{
	static char *buffer;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(Inf->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(Inf, &buffer, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buffer + i;

		check_chain(Inf, buffer, &j, i, len);
		while (j < len)
		{
			if (is_chain(Inf, buffer, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			Inf->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buffer;
	return (r);
}



/**
 * input_buf - buffers chained commands
 * @buffer: address of buffer
 * @Inf: parameter struct
 * @addlen: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *Inf, char **buffer, size_t *addlen)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*addlen)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(Inf, buffer, &len_p);
#endif
		if (r > 0)
		{
			if ((*buffer)[r - 1] == '\n')
			{
				(*buffer)[r - 1] = '\0';
				r--;
			}
			Inf->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(Inf, *buffer, Inf->histcount++);
			{
				*addlen = r;
				Inf->cmd_buf = buffer;
			}
		}
	}
	return (r);
}


/**
 * sigintHandler - blocks ctrl-C
 * @signal_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int signal_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * read_buf - reads a buffer
 * @Inf: parameter struct
 * @i: size
 * @buffer: buffer
 *
 * Return: r
 */
ssize_t read_buf(info_t *Inf, char *buffer, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(Inf->readfd, buffer, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}
