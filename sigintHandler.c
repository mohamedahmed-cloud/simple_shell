#include "shell.h"
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	printStr("\n");
	printStr("$ ");
	_putcharacter(BUF_FLUSH);
}
