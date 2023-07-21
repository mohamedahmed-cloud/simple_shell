#include "shell.h"

/**
 * is_cmd - determines if a
 * @info: the info
 * @full_path: full_path to the
 *
 * Return: 1 if true,
 */

int is_cmd(info_t *info, char *full_path)
{
	struct stat status;

	(void) info;
	if (!full_path || stat(full_path, &status))
		return (0);

	if (status.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
