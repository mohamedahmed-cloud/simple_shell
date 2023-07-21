#include "shell.h"

/**
 * **strtow2 -  function kernizer 1
 * @string: the input
 * @dimleter: the delemieter
 * Return: a pointer.
 */
char **strtow2(char *string, char dimleter)
{
	int i, j, k, m, our_words = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);

	for (i = 0; string[i] != '\0'; i++)
		if ((string[i] != dimleter && string[i + 1] == dimleter) ||
			(string[i] != dimleter && !string[i + 1]) ||
			string[i + 1] == dimleter)
			our_words++;

	if (our_words == 0)
		return (NULL);

	s = malloc((1 + our_words) * sizeof(char *));

	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < our_words; j++)
	{
		while (string[i] == dimleter && string[i] != dimleter)
			i++;
		k = 0;
		while (string[i + k] != dimleter && string[i + k]
			   && string[i + k] != dimleter)
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
