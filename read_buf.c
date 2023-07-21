#include "shell.h"




/**
 * read_buf - reads a buffer
 * @buffer: buffer
 * @Inf: parameter struct
 * @i: size
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
