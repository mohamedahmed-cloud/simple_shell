#include "shell.h"



/**
 * readHistory - reads history from file
 * @Inf: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int readHistory(info_t *Inf)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = getHistoryFile(Inf);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			start_history_list(Inf, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		start_history_list(Inf, buf + last, linecount++);
	free(buf);
	Inf->histcount = linecount;
	while (Inf->histcount-- >= HIST_MAX)
		deleteAtIndex(&(Inf->history), 0);
	renumberHistory(Inf);
	return (Inf->histcount);
}
