#include "shell.h"
/**
 * array_of_token - this function returns the number of tokens in a string
 *
 * @comm: the string to be tokenized
 * @token_num: the number of tokens in the string
 * Return: an array of tokens
 */
char **array_of_token(char *comm, int token_num)
{
	char *tkn;
	char **arr;
	int i = 0, j;

	tkn = strtok(comm, " ");
	if (tkn == NULL)
	{
		free(tkn);
		return (NULL);
	}
	else
		arr = malloc(sizeof(char *) * (token_num + 1));
	while (tkn)
	{
		arr[i] = malloc(_strlen(tkn) + 1);
		if (!arr[i])
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			perror("cannot allocate memory");
			exit(0);
		}
		_strcpy(arr[i], tkn);
		i++;
		tkn = strtok(NULL, " ");
	}
	arr[i] = NULL;
	free(tkn);
	return (arr);
}
