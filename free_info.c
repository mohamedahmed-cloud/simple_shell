#include "shell.h"


/**
 * free_info - frees info_t struct fields
 * @Inf: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *Inf, int all)
{
	ffree(Inf->argv);
	Inf->argv = NULL;
	Inf->path = NULL;
	if (all)
	{
		if (!Inf->cmd_buf)
			free(Inf->arg);
		if (Inf->env)
			free_list(&(Inf->env));
		if (Inf->history)
			free_list(&(Inf->history));
		if (Inf->alias)
			free_list(&(Inf->alias));
		ffree(Inf->environ);
		Inf->environ = NULL;
		bfree((void **) Inf->cmd_buf);
		if (Inf->readfd > 2)
			close(Inf->readfd);
		_putchar(BUF_FLUSH);
	}
}
