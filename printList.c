#include "shell.h"
/**
 * printList - prints all e
 * @h: pointer to
 *
 * Return: siz
 */
size_t printList(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		printStr(numberConverting(h->num, 10, 0));
		_putcharacter(':');
		_putcharacter(' ');
		printStr(h->str ? h->str : "(nil)");
		printStr("\n");
		h = h->next;
		i++;
	}
	return (i);
}
