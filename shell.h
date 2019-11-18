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

void get_stdin(char *envp[]);
int read_file(int argc, char *argv[]);
int get_commands(char *buffer);
/**
 * interactive_mode - Prints a prompt
 * Description: This function prints a prompt
 * @void:
 * Return:
 */
void interactive_mode(void);

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: Params
 * @envp: Enviroment params
 * Return: 1
 */
int execute_commands(char *argv[], char *envp[]);

#endif
