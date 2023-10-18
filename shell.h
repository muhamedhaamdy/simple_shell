#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


#define UNUSED(x) (void)(x)
/**
 * struct builtinfunc - struct for builtins
 * @str: the string to compare
 * @func: the function to run
 */
typedef struct builtinfunc
{
	char *str;
	void (*func)();
} bif;

extern char **environ;
#ifndef env
#define env environ
#endif

int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *a, char *b);
char *_getenv();
char **array_of_token(char *comm, int token_num);
char *check_path(char *command);
char *get_path(char *command);
void exe(char **av, char *path);
int _atoi(char *str);
void exit_sh(char *str);
void printenv(char *str);
int preprocess(char **commcpy);
void free2DandCommand(char **arr, char *command);

#endif
