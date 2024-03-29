#include "shell.h"

/**
 * freePtr - To Free the pointer
 * @our_pointer: address of the
 * Return: 1 if the is the pointer and 0 else
 */

int freePtr(void **our_pointer)
{
	if (our_pointer && *our_pointer)
	{

		free(*our_pointer);
		*our_pointer = NULL;
		return (1);
	}

	return (0);
}

