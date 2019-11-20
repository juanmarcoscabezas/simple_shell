#include "shell.h"

/**
 * get_commands - Gets the commands
 * Description: This function gets commands & break them in tokens
 * @cp_argv: Copy of the original argv (the name of the executable)
 * @buffer: Params
 * @envp: Enviroment params
 * @n_commands: the number of commands given until this point.
 * Return: Always 0
 */
int get_commands(char *cp_argv[], char *buffer, char *envp[], int *n_commands)
{
	char *token;
	char **tokens;
	int pos = 0;

	tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
	{
		perror("Error on allocation");
		exit(100);
	}
	token = strtok(buffer, " \n");

	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, " \n");
	}
	tokens[pos] = NULL;
	execute_commands(cp_argv, tokens, envp, n_commands);
	free(tokens);
	return (0);
}
