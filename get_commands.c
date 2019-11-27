#include "shell.h"

/**
 * get_commands - Gets the commands
 * Description: This function gets commands & break them in tokens
 * @argv: arguments passed to the shell
 * @commands: commands passed to the shell
 * @envp: enviroment variables passed to the shell
 * @n_commands: the number of commands given until this point.
 * Return: Always 0
 */
int get_commands(char *argv[], char *commands, char *envp[], int *n_commands)
{
	char *token;
	char **tokens;
	int pos = 0;
	int execute;

	tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
	{
		perror("Error on allocation");
		exit(100);
	}
	token = strtok(commands, " \n");

	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, " \n");
	}
	tokens[pos] = NULL;
	execute = execute_commands(argv, tokens, envp, n_commands);
	free(tokens);
	return (execute);
}
