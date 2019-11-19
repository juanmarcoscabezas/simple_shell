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

typedef struct comands
{
	char *bin;
	char *options;
	char *op;
} comands_t;

void get_stdin(char *envp[]);
int read_file(int argc, char *argv[]);
int get_commands(char *buffer, char *envp[]);
char *_getenv(char *envp[]);
<<<<<<< HEAD
char *check_access(char *path, char *command);
=======
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
>>>>>>> be3c18a0794087d2cac9f38b8d574a77de1b14e1
/**
 * interactive_mode - Prints a prompt
 * Description: This function prints a prompt
 * @void:
 * Return:
 */
void interactive_mode(char *envp[]);

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: Params
 * @envp: Enviroment params
 * Return: 1
 */
int execute_commands(char *argv[], char *envp[]);

#endif
