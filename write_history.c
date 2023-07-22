#include "shell.h"


/**
 * writeHistory - creates a file, or appends to an existing file
 * @Inf: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int writeHistory(info_t *Inf)
{
	ssize_t fd;
	char *filename = getHistoryFile(Inf);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = Inf->history; node; node = node->next)
	{
		_printFd(node->str, fd);
		printFd('\n', fd);
	}
	printFd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
