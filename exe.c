#include "shell.h"
/**
 * exe - this function executes a command
 *
 * @av: the arguments
 * @path: the path of the command
 */
void exe(char **av, char *path)
{
	int ac;
	
	if (execve(path, av, __environ) == -1)
	{
		_puts("./hsh");
		_putchar(':'), _putchar(' ');
		_putchar('1'), _putchar(':'), _putchar(' ');
		_puts(path);
		_puts(": not found\n");
		free(path);
		for (ac = 0; av[ac]; ac++)
			free(av[ac]);
		free(av);
		exit(127);
	}
}
