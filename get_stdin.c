#include "shell.h"
#define LSH_TOK_DELIM " \t\r\n\a"

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
	char auxiliar[100];
	int pos = 0;
	char ch;
	char **tokens = malloc(sizeof(char *) * 64);
	char *token;

	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		auxiliar[pos] = ch;
		pos++;
	}
	auxiliar[pos] = '\0';

	pos = 0;
	token = strtok(auxiliar, LSH_TOK_DELIM);
	while (token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	execute_commands(cp_argv, tokens, envp, number_commands);
}
