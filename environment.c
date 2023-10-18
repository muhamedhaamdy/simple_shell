#include "shell.h"

/**
 * _getenv - this function returns the PATH
 *
 * Return: the PATH
 */
char *_getenv()
{
	int i = 0;
	char **e = env;

	while (e[i])
	{
		if (e[i][0] == 'P' && e[i][1] == 'A' && e[i][2] == 'T' && e[i][3] == 'H')
		{
			return (e[i] + 5);
		}
		i++;
	}
	return (NULL);
}

/**
 * printenv - this function prints the environment
 *
 * @str: the string to be freed
 */
void printenv(char *str)
{
	char **e = env;
	int i = 0;

	UNUSED(str);
	while (e[i])
	{
		_puts(e[i]);
		_putchar('\n');
		i++;
	}
}
