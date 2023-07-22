#include "shell.h"
/**
 * replaceString - this function is used to replace the string.
 * @old_String: old string
 * @new_string: new string.
 *
 * Return: 1 if sucess
 */
int replaceString(char **old_String, char *new_string)
{
	free(*old_String);
	*old_String = new_string;
	return (1);
}
