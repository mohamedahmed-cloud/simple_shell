#include "shell.h"

/**
 * **splitStr - splits the stringing.
 * @string: the input
 * @d: the delimiter
 * Return: a pointer to an
 */

char **splitStr(char *string, char *d)
{
	int i, j, k, m, our_words = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);

	if (!d)
		d = " ";

	for (i = 0; string[i] != '\0'; i++)
		if (!isDelim(string[i], d) && (isDelim(string[i + 1], d)
									   || !string[i + 1]))
			our_words++;
	if (our_words == 0)
		return (NULL);
	s = malloc((1 + our_words) * sizeof(char *));
	if (!s)
		return (NULL);

	for (i = 0, j = 0; j < our_words; j++)
	{
		while (isDelim(string[i], d))
			i++;
		k = 0;
		while (!isDelim(string[i + k], d) && string[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = string[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

