#include "shell.h"
#define LSH_TOK_DELIM " \t\r\n\a"

/**
 * main.c - function main entry.
 * Description: main function for our shell
 * @argc: number of arguments pass to the shell
 * @argv: char ** pass to the shell
 * @envp: enviroment pass to the shell
 * Return: 0 on success
 **/
int main(int argc, char *argv[], char *envp[])
{
	char auxiliar[100];
	int pos = 0;
	char ch;
	char **tokens = malloc(sizeof(char *) * 64);
	char *token;

	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
			
			return (1);
		}
		else
		{
			get_stdin(envp);
			return (2);
		}
	}
	else
	{
		execute_commands(++argv, envp);
		return (0);
	}
}
