#include "shell.h"

/**
 * get_commands - Gets the commands
 * Description: This function gets commands
 * @void
 * Return: Always 0
 */
int get_commands(char *buffer, char *envp[], int *number_commands)
{
	char *token;
	char **tokens = malloc(sizeof(char *) * 64);
	int pos = 0;

	token = strtok(buffer, " \n");

	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, " \n");
	}
	tokens[pos] = NULL;
	execute_commands(tokens, envp, number_commands);
	return (0);
}
