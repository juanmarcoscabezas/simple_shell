#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void get_stdin(char *envp[]);
/**
 * print_prompt - Prints a prompt
 * Description: This function prints a prompt
 * @void:
 * Return:
 */
void print_prompt(void);

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: Params
 * @envp: Enviroment params
 * Return: 1
 */
int execute_commands(char *argv[], char *envp[]);

#endif
