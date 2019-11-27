#include "shell.h"

/**
 * print_parameters - Function to print parameters becouse of betty
 * Description: Function to print parameters becouse of betty
 * @argv_param: Name of file
 * @n_com: Number of commands inserted
 * @com_cpy: Command that was executed
 * Return:
 */
void print_parameters(char *argv_param, int *n_com, char *com_cpy)
{
	_puts(argv_param);
	_puts(": ");
	print_number(n_com);
	_puts(": ");
	_puts(com_cpy);
	_puts(": not found\n");
}

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: arguments passed to the shell
 * @tokens: Options tokenized from a command
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * Return: 1
 */
int execute_commands(char *argv[], char *tokens[], char *envp[], int *n_com)
{
	int status, is_accessible, built_in_result;
	pid_t pid;
	char *path = NULL, *com_cpy;

	/* Check built-in functions */
	built_in_result = built_in(argv, tokens, envp, n_com);
	if (built_in_result != 1)
		return (built_in_result);
	/* Check if the file exists */
	is_accessible = access(tokens[0], F_OK | X_OK | R_OK);
	/* If not accessible try to find in PATH */
	if (is_accessible == -1)
	{
		path = _getenv(envp, "PATH");
		com_cpy = tokens[0];
		tokens[0] = check_access(path, tokens[0]);
		if (tokens[0] == NULL)
		{
			print_parameters(argv[0], n_com, com_cpy);
			(*n_com)++;
			if (path)
				free(path);
			return (127);
		}
	}
	if (path && is_accessible == -1)
		free(path);
	(*n_com)++;
	pid = fork();
	if (pid == 0)
	{
		execve(tokens[0], tokens, envp);
		exit(0);
	}
	else
		wait(&status);
	if (is_accessible == -1)
		free(tokens[0]);
	return (0);
}
