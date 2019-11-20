#include "shell.h"
#define LSH_TOK_DELIM " \t\r\n\a"

void process_command(char *cp_argv[], char *envp[], int *number_commands, char *command)
{
	char *token;
	char **tokens = malloc(sizeof(char *) * 64);
	int pos = 0;

	token = strtok(command, LSH_TOK_DELIM);
	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	execute_commands(cp_argv, tokens, envp, number_commands);
	free(tokens);
}

/**
 * get_stdin - function to get stdin.
 * Description: main
 * @cp_argv: Copy of the original argv (the name of the executable)
 * @envp: enviroment pass to the shell
 * @number_commands: the number of commands given until this point.
 * Return: 0 on success
 **/
void get_stdin(char *cp_argv[], char *envp[], int *number_commands)
{
	char *command = malloc(sizeof(char) * 1024);
	int pos = 0;
	char ch;

	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		command[pos] = ch;
		if (ch == '\0' || ch == '\n')
		{
			process_command(cp_argv, envp, number_commands, command);
			pos = -1;
		}
		pos++;
	}
	free(command);
}
