#include "shell.h"
/**
 * check_path - this function check the path of a command
 *
 * @command: the command to be searched
 * Return: the path of the command
 */
char *check_path(char *command)
{
	struct stat buff;
	char *comm_path;

	if (!stat(command, &buff))
	{
		comm_path = malloc(_strlen(command) + 1);
		if (!comm_path)
		{
			free(comm_path);
			return (NULL);
		}
		_strcpy(comm_path, command);
		return (comm_path);
	}
	return (NULL);
}
/**
 * get_path - this function returns the path of a command
 *
 * @command: the command to be searched
 * Return: the path of the command
 */
char *get_path(char *command)
{
	char *path, *pathcpy, *tkn, *comm_path = check_path(command);
	struct stat buff;

	if (comm_path)
		return (comm_path);
	free(comm_path);
	path = _getenv();
	pathcpy = malloc(sizeof(char) * 1000);
	if (!pathcpy)
	{
		free(path);
		free(pathcpy);
		return (NULL);
	}
	_strcpy(pathcpy, path);
	tkn = strtok(pathcpy, ":");
	while (tkn)
	{
		comm_path = malloc(_strlen(tkn) + _strlen(command) + 2);
		if (!comm_path)
		{
			free(pathcpy);
			free(tkn);
			free(comm_path);
			return (NULL);
		}
		_strcpy(comm_path, tkn);
		_strcat(comm_path, "/");
		_strcat(comm_path, command);
		_strcat(comm_path, "\0");
		if (!stat(comm_path, &buff))
		{
			free(pathcpy);
			return (comm_path);
		}
		tkn = strtok(NULL, ":");
		free(comm_path);
	}
	
	free(pathcpy);
	free(tkn);
	return (NULL);
}