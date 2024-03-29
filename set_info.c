#include "shell.h"


/**
 * setInformation - initializes info_t struct
 * @argumentv: argument vector
 * @Inf: struct address
 */
void setInformation(info_t *Inf, char **argumentv)
{
	int i = 0;

	Inf->fname = argumentv[0];
	if (Inf->arg)
	{
		Inf->argv = splitStr(Inf->arg, " \t");
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
			Inf->argc = i;

		replaceAlias(Inf);
		replaceVariables(Inf);
	}
}
