#include "shell.h"
/**
 * initialze_buff - this function initializes the buffer
 *
 * @buff : the buffer to be filled
 * @buffsize : the size of the buffer
 */
void initialze_buff(char **buff, size_t *buffsize)
{
	*buffsize = 1024;
	*buff = malloc(sizeof(char) *  (*buffsize));
	if (!buff)
	{
		free(buff);
		exit(0);
	}
}

/**
 * _getline - this function reads a line from the standard input
 *
 * @buff : the buffer to be filled
 * @buffsize : the size of the buffer
 * Return: the number of bytes read
 */
ssize_t _getline(char **buff, size_t *buffsize)
{
	char line;
	static ssize_t read_byte;
	size_t len = 0;

	if (!*buff || !buffsize)
	{
		initialze_buff(buff, buffsize);
	}
	while (1)
	{
		read_byte = read(STDIN_FILENO, &line, 1);
		if (read_byte == -1)
		{
			free(*buff);
			return (-1);
		}
		else if ((read_byte == 0 || line == '\n') && (len == 0 && read_byte == 0))
			return (-1);
		(*buff)[len] = line;
		len++;
		if (read_byte == 0 || line == '\n')
		{
			(*buff)[len] = '\0';
			return (len);
		}
		if (len >= *buffsize)
		{
			*buffsize *= 1024;
			*buff = realloc(*buff, *buffsize);
			if (buff == NULL)
			{
				free(*buff);
				return (-1);
			}
		}
	}
}

