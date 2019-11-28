#include "shell.h"

/**
 * get_commands - Gets the commands
 * Description: This function gets commands & break them in tokens
 * @argv: arguments passed to the shell
 * @cmds: commands passed to the shell
 * @envp: enviroment variables passed to the shell
 * @n_cmds: the number of commands given until this point.
 * @lo: Last output from a command
 * Return: Always 0
 */
int get_commands(char *argv[], char *cmds, char *envp[], int *n_cmds, int *lo)
{
	char *token;
	char **tokens;
	int pos = 0;
	int execute;

	tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
	{
		perror("Error on allocation");
		exit(0);
	}
	token = strtok(cmds, " \t\r\n\a");

	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[pos] = NULL;
	execute = exec_cmds(argv, tokens, envp, n_cmds, lo);
	free(tokens);
	return (execute);
}
