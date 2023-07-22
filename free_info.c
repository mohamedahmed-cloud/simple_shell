#include "shell.h"


/**
 * freeInformation - frees info_t struct fields
 * @Inf: struct address
 * @all: true if freeing all fields
 */
void freeInformation(info_t *Inf, int all)
{
	fS(Inf->argv);
	Inf->argv = NULL;
	Inf->path = NULL;
	if (all)
	{
		if (!Inf->cmd_buf)
			free(Inf->arg);
		if (Inf->env)
			freeList(&(Inf->env));
		if (Inf->history)
			freeList(&(Inf->history));
		if (Inf->alias)
			freeList(&(Inf->alias));
		fS(Inf->environ);
		Inf->environ = NULL;
		freePtr((void **) Inf->cmd_buf);
		if (Inf->readfd > 2)
			close(Inf->readfd);
		_putcharacter(BUF_FLUSH);
	}
}
