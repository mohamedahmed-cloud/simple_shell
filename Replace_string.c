#include "shell.h"
/**
 * replace_string - this function is used to replace the string.
 * @old_String: old string
 * @new_string: new string.
 *
 * Return: 1 if sucess
 */
int replace_string(char **old_String, char *new_string)
{
	free(*old_String);
	*old_String = new_string;
	return (1);
}
