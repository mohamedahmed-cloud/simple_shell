#include "shell.h"

/**
 * printError - prints an error message
 * @Inf: the parameter & return info struct
 * @errorstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void printError(info_t *Inf, char *errorstr)
{
	_ePut(Inf->fname);
	_ePut(": ");
	printDecimal(Inf->line_count, STDERR_FILENO);
	_ePut(": ");
	_ePut(Inf->argv[0]);
	_ePut(": ");
	_ePut(errorstr);
}
