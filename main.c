#include "shell.h"

/**
 * main - function main entry.
 * Description: main function for our shell
 * @argc: number of arguments passed to the shell
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
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
		}
		else
		{
			get_stdin(argv, envp, &number_commands);
		}
	}
	else
	{
		read_file(argv, envp, &number_commands);
	}
	return (0);
}
