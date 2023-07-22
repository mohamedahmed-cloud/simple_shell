#include "shell.h"


/**
 * getHistoryFile - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *getHistoryFile(info_t *info)
{
	char *buf, *dir;

	dir = _getEnvironment(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strLen(dir) + _strLen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strCopy(buf, dir);
	strConcat(buf, "/");
	strConcat(buf, HIST_FILE);
	return (buf);
}
