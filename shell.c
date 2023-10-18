#include "shell.h"
/**
 * main - this is the entry function of the shell
 *
 * @ac: the number of arguments
 * @av: the arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *command = NULL;
	int token_num;
	pid_t child_pid;

	UNUSED(ac);
	while (1)
	{
		token_num = preprocess(&command);
		if (!token_num)
		{
			free(command);
			continue;
		}
		av = array_of_token(command, token_num);
		free(command);
		if (!av || !av[0])
			continue;
		command = get_path(av[0]);
		if (!command)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", av[0]);
			free2DandCommand(av, command);
			exit(127);
		}
		child_pid = fork();
		if (child_pid == -1)
			free2DandCommand(av, command);
		else if (child_pid == 0)
		{
			exe(av, command);
			free2DandCommand(av, command);
			return (0);
		}
		else
			waitpid(child_pid, NULL, 0);
		free2DandCommand(av, command);
	}
	return (0);
}
