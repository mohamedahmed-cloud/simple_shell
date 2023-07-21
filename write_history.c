#include "shell.h"


/**
 * write_history - creates a file, or appends to an existing file
 * @Inf: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *Inf)
{
	ssize_t fd;
	char *filename = get_history_file(Inf);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = Inf->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
