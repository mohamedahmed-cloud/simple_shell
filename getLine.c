#include "shell.h"


/**
 * _getLine - gets the next line of input from STDIN
 * @Inf: parameter struct
 * @length: size of reallocated ptr buffer if not NULL
 * @ptr: address of pointer to buffer, reallocated or NULL
 *
 * Return: s
 */
int _getLine(info_t *Inf, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = readBuffer(Inf, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = searchStr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = myReallocate(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strCat(new_p, buf + i, k - i);
	else
		_strcpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
