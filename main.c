#include "shell.h"

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
	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			interactive_mode(envp);
			return (0);
		}
		else
		{
			get_stdin(envp);
			return (1);
		}
	}
	else
	{
		read_file(--argc, ++argv);
		return (2);
	}
}
