#include "shell.h"

#define LSH_TOK_DELIM " \t\r\n\a"

/**
 * process_command - Process every command
 * Description: THis function proccesses all the commands and execute it
 * @cp_argv: Copy of the original argv
 * @envp: Enviroment variable
 * @n_cmds: Number of commands executed
 * @command: Command to proccess
 * Return: the value of execute_commands
 */
int process_command(char *argv[], char *envp[], int *n_com, char *command)
{
	char *token;
	char **tokens = malloc(sizeof(char *) * 64);
	int pos = 0;
	int execute;

	token = strtok(command, LSH_TOK_DELIM);
	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	execute = execute_commands(argv, tokens, envp, n_com);
	free(tokens);
	return (execute);
}

/**
 * get_stdin - function to get stdin.
 * Description: main
 * @cp_argv: Copy of the original argv (the name of the executable)
 * @envp: enviroment pass to the shell
 * @number_commands: the number of commands given until this point.
 * Return: 0 on success
 **/
void get_stdin(char *argv[], char *envp[], int *number_commands)
{
	char *command = malloc(sizeof(char) * 1024);
	int pos = 0;
	char ch;
	int execute;

	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		command[pos] = ch;
		if (ch == '\0' || ch == '\n')
		{
			execute = process_command(argv, envp, number_commands, command);
			pos = -1;
			command = malloc(sizeof(char) * 1024);
			_memset(command, '\0', 1024);
		}
		pos++;
	}
	exit(execute);
}
