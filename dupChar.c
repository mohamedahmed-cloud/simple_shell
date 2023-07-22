/**
 * debugChar -	debug the chars.
 * @pathstr: the path of the string
 * @start_point: start_point of all of you
 * @stop_point:	to stop_point
 *
 * Return: point
 */


char *debugChar(char *pathstr, int start_point, int stop_point)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start_point; i < stop_point; i++)
	{
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	}

	buf[k] = 0;
	return (buf);
}
