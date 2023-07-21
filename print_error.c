#include "shell.h"

/**
 * print_error - prints an error message
 * @Inf: the parameter & return info struct
 * @errorstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *Inf, char *errorstr)
{
	_eputs(Inf->fname);
	_eputs(": ");
	print_d(Inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(Inf->argv[0]);
	_eputs(": ");
	_eputs(errorstr);
}
