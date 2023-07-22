#include "shell.h"

/**
 * myReallocate - reallcate the memory
 * @pointer: pointer to the previous size
 * @our_old_size: our old size
 * @our_new_size: our new size
 *
 * Return: the pionter to the new size.
 */

void *myReallocate(void *pointer,
				   unsigned int our_old_size, unsigned int our_new_size)
{
	char *p;

	if (!pointer)
	{
		return (malloc(our_new_size));
	}
	if (!our_new_size)
	{
		return (free(pointer), NULL);
	}
	if (our_new_size == our_old_size)
	{
		return (pointer);
	}

	p = malloc(our_new_size);

	if (!p)
	{
		return (NULL);
	}

	our_old_size = our_old_size < our_new_size ? our_old_size : our_new_size;

	while (our_old_size--)
	{
		p[our_old_size] = ((char *)pointer)[our_old_size];
	}

	free(pointer);
	return (p);
}

