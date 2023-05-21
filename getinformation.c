#include "shell.h"



/**
 * set_info - initializes info_t struct
 * @argumentv: argument vector
 * @Inf: struct address
 */
void set_info(info_t *Inf, char **argumentv)
{
	int i = 0;

	Inf->fname = argumentv[0];
	if (Inf->arg)
	{
		Inf->argv = strtow(Inf->arg, " \t");
		if (!Inf->argv)
		{
			Inf->argv = malloc(sizeof(char *) * 2);
			if (Inf->argv)
			{
				Inf->argv[0] = _strdup(Inf->arg);
				Inf->argv[1] = NULL;
			}
		}
		for (i = 0; Inf->argv && Inf->argv[i]; i++)
			;
		Inf->argc = i;

		replace_alias(Inf);
		replace_vars(Inf);
	}
}


/**
 * clear_info - initializes info_t struct
 * @Inf: struct address
 */
void clear_info(info_t *Inf)
{
	Inf->arg = NULL;
	Inf->argv = NULL;
	Inf->path = NULL;
	Inf->argc = 0;
}

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
		bfree((void **)Inf->cmd_buf);
		if (Inf->readfd > 2)
			close(Inf->readfd);
		_putchar(BUF_FLUSH);
	}
}
