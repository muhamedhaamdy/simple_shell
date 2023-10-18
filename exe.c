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
		perror("error: failed to execute command\n");
		free(path);
		for (ac = 0; av[ac]; ac++)
			free(av[ac]);
		free(av);
		exit(127);
	}
}
