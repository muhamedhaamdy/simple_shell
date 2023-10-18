#include "shell.h"
/**
 * _atoi - this function converts a string to an integer
 *
 * @str: the string to be converted
 * Return: the integer value of the string
 */
int _atoi(char *str)
{
	int i = 0;
	int res = -1;
	int sign = 1;

	if (str[0] == '-')
	{
		perror("./hsh: 1: exit: Illegal number: -98");
		exit(2);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * sign;
	if (res == -1)
	{
		perror("./hsh: 1: exit: Illegal number: -98");
		exit(2);
	}
	return (res);
}
/**
 * exit_sh - this function exits the shell
 *
 * @str: the string to be converted to an integer
 */
void exit_sh(char *str)
{
	int res;

	if (str == NULL)
	{
		free(str);
		exit(0);
	}
	res = _atoi(str);
	free(str);
	exit(res);
}
