#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 *
 * @str: the string to be printed
 */
void _puts(char *str)
{
	char i = *str;
	int c = 0;

	while (i != '\0')
	{
		c++;
		_putchar(i);
		i = *(str + c);
	}
}

/**
 * _strlen - returns the length of a string
 *
 * @str: the string to be measured
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int count = 0;

	while (str  && str[count])
		count++;
	return (count);
}

/**
 * _strcpy - copies the string pointed to by src to dest
 *
 * @dest: the destination buffer
 * @src: the source string
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = _strlen(src);
	for (i = 0; i < len; i++)
		*(dest + i) = *(src + i);
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: the destination string
 * @src: the source string
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	for (j = 0; dest[j] != '\0'; j++)
		;
	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

