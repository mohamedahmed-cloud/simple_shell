#include "shell.h"


/**
 * clearInformation - initializes info_t struct
 * @Inf: struct address
 */
void clearInformation(info_t *Inf)
{
	Inf->arg = NULL;
	Inf->argv = NULL;
	Inf->path = NULL;
	Inf->argc = 0;
}
