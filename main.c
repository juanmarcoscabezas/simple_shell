#include "shell.h"

/**
 * main - function main entry.
 * Description: main function for our shell
 * @argc: number of arguments pass to the shell
 * @argv: char ** pass to the shell
 * @envp: enviroment pass to the shell
 * Return: 0 on success
 **/
int main(int argc, char *argv[], char *envp[])
{
	int number_commands = 1;

	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			interactive_mode(argv, envp, &number_commands);
			return (0);
		}
		else
		{
			get_stdin(argv, envp, &number_commands);
			return (1);
		}
	}
	else
	{
		read_file(++argv);
		return (2);
	}
}
