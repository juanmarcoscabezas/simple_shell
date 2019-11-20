#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

typedef struct comands
{
	char *bin;
	char *options;
	char *op;
} comands_t;

void get_stdin(char *cp_argv[], char *envp[], int *number_commands);
int read_file(int argc, char *argv[]);
int get_commands(char *cp_argv[], char *buffer, char *envp[], int *number_commands);
char *_getenv(char *envp[]);
char *check_access(char *path, char *command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void str_replace(char *dest, char *src);
/**
 * interactive_mode - Prints a prompt
 * Description: This function prints a prompt
 * @void:
 * Return:
 */
void interactive_mode(char *cp_argv[], char *envp[], int *number_commands);

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: Params
 * @envp: Enviroment params
 * Return: 1
 */
int execute_commands(char *cp_argv[], char *argv[], char *envp[], int *number_commands); 

#endif
