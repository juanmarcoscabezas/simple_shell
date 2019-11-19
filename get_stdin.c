#include "shell.h"
#define LSH_TOK_DELIM " \t\r\n\a"

/**
 * get_stdin.c - function to get stdin.
 * Description: main 
 * @argc: number of arguments pass to the shell
 * @argv: char ** pass to the shell
 * @envp: enviroment pass to the shell
 * Return: 0 on success
 **/
void get_stdin(char *envp[])
{
	char auxiliar[100];
	int pos = 0;
	char ch;
	char **tokens = malloc(sizeof(char *) * 64);
	char *token;

	while(read(STDIN_FILENO, &ch, 1) > 0)
	{
		auxiliar[pos] = ch;
		pos++;
	}
	auxiliar[pos] = '\0';

	pos = 0;
	token = strtok(auxiliar, LSH_TOK_DELIM);
	while(token)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	execute_commands(tokens, envp, NULL);
}
