#include "shell.h"

/**
 * process_command2 - Process every command
 * Description: THis function proccesses all the commands and execute it
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * @command: Command to proccess
 * Return: the value of execute_commands
 */
int process_command2(char *argv[], char *envp[], int *n_com, char *command)
{
	char *token;
	char **tokens = malloc(sizeof(char *) * 64);
	int pos = 0;
	int execute;

	token = strtok(command, " \t\r\n\a");
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
 * get_stdin2 - function to get stdin.
 * Description: main
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
 * @number_commands: the number of commands given until this point.
 * Return: 0 on success
 **/
void get_stdin2(char *argv[], char *envp[], int *number_commands)
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
			execute = process_command2(argv, envp, number_commands, command);
			pos = -1;
			command = malloc(sizeof(char) * 1024);
			_memset(command, '\0', 1024);
		}
		pos++;
	}
	exit(execute);
}

/**
 * read_file - function
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * Return: actual number of letters it could print
 */
int read_file(char *argv[], char *envp[], int *n_com)
{
	int file, letters = 1024;
	char *buffer, *filename = argv[0], n;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file);
		return (0);
	}
	n = read(file, buffer, letters);
	if (n == -1)
	{
		free(buffer);
		close(file);
		return (-1);
	}
	n = write(1, buffer, n);
	/* (STDOUT_FILENO, "%s", buffer); */
	if (n == -1)
	{
		free(buffer);
		close(file);
		return (-1);
	}
	get_stdin2(argv, envp, n_com);
	free(buffer);
	close(file);
	return (n);
}
