#include "shell.h"

/**
 * process_command - Process every command
 * Description: THis function proccesses all the commands and execute it
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * @command: Command to proccess
 * Return: the value of execute_commands
 */
int process_command(char *argv[], char *envp[], int *n_com, char *command)
{
	char *token = NULL;
	char **tokens = NULL;
	char *command_cpy = command;
	int pos = 0;
	int execute = 0;

	tokens = malloc(sizeof(char *) * 64);

	token = strtok(command_cpy, " \t\r\n\a");
	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[pos] = NULL;
	execute = execute_commands(argv, tokens, envp, n_com);
	free(tokens);
	return (execute);
}

/**
 * get_stdin - function to get stdin.
 * Description: main
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
 * @number_commands: the number of commands given until this point.
 * Return: 0 on success
 **/
void get_stdin(char *argv[], char *envp[], int *number_commands)
{
	char *command;
	int pos = 0;
	char ch = '\0';
	int execute = 0;

	command = malloc(sizeof(char) * 1024);
	if (!command)
		exit(0);
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		command[pos] = ch;
		if (ch == '\0' || ch == '\n')
		{
			command[pos + 1] = '\0';
			if (verify_tab(command, _strlen(command)) == 0)
				execute = process_command(argv, envp, number_commands, command);
			pos = -1;
			free(command);
			command = malloc(sizeof(char) * 1024);
			_memset(command, '\0', 1024);
		}
		pos++;
	}
	free(command);
	exit(execute);
}
