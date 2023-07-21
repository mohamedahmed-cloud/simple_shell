#include "shell.h"


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
