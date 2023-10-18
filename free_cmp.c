#include "shell.h"
/**
 * _strcmp - this function compares two strings
 *
 * @a: the first string
 * @b: the second string
 * Return: 0 if the strings are equal, 1 otherwise
 */
int _strcmp(char *a, char *b)
{
	int i;

	for (i = 0; a[i] && b[i]; i++)
		if (a[i] != b[i])
			return (1);
	if (a[i] || b[i])
		return (1);
	return (0);
}
/**
 * free2DandCommand - this function frees a 2D array and a string
 *
 * @arr: the 2D array to be freed
 * @command: the string to be freed
 */
void free2DandCommand(char **arr, char *command)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	free(command);
}
