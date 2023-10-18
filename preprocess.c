#include "shell.h"
/**
 * number_fo_tokns - this function returns the number of tokens in a string
 *
 * @commcpy: the string to be tokenized
 * Return: the number of tokens in the string
 */
int number_fo_tokns(char *commcpy)
{
	char *tkn = strtok(commcpy, " ");
	int token_num = 0;

	while (tkn)
	{
		token_num++;
		tkn = strtok(NULL, " ");
	}
	free(tkn);
	free(commcpy);
	return (token_num);
}
/**
 * check_EOF - check for end of file condition
 *
 * @n : the size of line
 * @command : the string that should be freed
*/
void check_EOF(ssize_t n, char *command)
{
	if (n == -1)
	{
		free(command);
		exit(0);
	}
}

/**
 * preprocess - this function returns the number of tokens in a string
 *
 * @commcpy: the string to be tokenized
 * Return: the number of tokens in the string
 */
int preprocess(char **commcpy)
{
	bif builtin[] = { {"exit", exit_sh}, {"env", printenv}, {NULL, NULL} };
	ssize_t read;
	size_t letters = 0;
	char *command = NULL, *tkn, *another_cpy;
	int len, i = 0;

	read = getline(&command, &letters, stdin);
	check_EOF(read, command);
	len = _strlen(command);
	command[len - 1] = '\0';
	*commcpy = malloc(sizeof(char) * len);
	another_cpy = malloc(sizeof(char) * len);
	if (!*commcpy || !another_cpy)
	{
		perror("cannot allocate memory");
		free(command);
		free(*commcpy);
		free(another_cpy);
		exit(0);
	}
	_strcpy(*commcpy, command);
	_strcpy(another_cpy, command);
	tkn  = strtok(command, " ");
	while (builtin[i].str != NULL)
	{
		if (tkn && !_strcmp(tkn, builtin[i].str))
		{
			tkn = strtok(NULL, " ");
			free(command);
			free(another_cpy);
			free(*commcpy);
			builtin[i].func(tkn);
			free(tkn);
			return (0);
		}
		i++;
	}
	free(command);
	return (number_fo_tokns(another_cpy));
}
