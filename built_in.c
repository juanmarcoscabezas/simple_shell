#include "shell.h"

/**
 * check_exit - Look for the flag of exit
 * Description: This function checks the flag of exit
 * @cp_argv: Copy of passed arguments to main
 * @number: Number to check if is an integer
 * @n_com: Number of commands executed
 * Return: 0 if success, -1 otherwise
 */
int check_exit(char *argv[], char *number, int *n_com)
{
	int counter = 0;

	while (number[counter] != '\0')
	{
		if (number[counter] < 48 || number[counter] > 57)
		{
			printf("%s: %d: exit: Illegal number: %s\n", argv[0], *n_com, number);
			return (127);
		}
		counter++;
	}
	return (0);
}

/**
 * built_in - Built-ins
 * Description: This function is to check the built-ins
 * @cp_argv: Copy of passed arguments to main
 * @argv: Parameter to check if it's a built-in
 * @envp: Enviroment values
 * @n_com: Number of commands executed
 * Return: the flag passed to exit, -1 otherwise
 */
int built_in(char *argv[], char *tokens[], char *envp[], int *n_com)
{
	int counter = 0, chdir_exec;
	char *home;

	if (tokens != NULL)
	{
		if (tokens[0])
		{
			if (_strcmp(tokens[0], "exit") == 0)
			{
				if (tokens[1])
				{
					if (check_exit(argv, tokens[1], n_com) == 0)
						exit(_atoi(tokens[1]));
					(*n_com)++;
					return (127);
				}
				exit(0);
			}
			if (_strcmp(tokens[0], "env") == 0)
			{
				if (tokens[1])
				{
					printf("env: %s: No such file or directory\n", tokens[1]);
					(*n_com)++;
					return (127);
				}
				while (envp[counter])
				{
					printf("%s\n", envp[counter]);
					counter++;
				}
				(*n_com)++;
				return (0);
			}
			if (_strcmp(tokens[0], "cd") == 0)
			{
				if (tokens[1])
				{
					chdir_exec = chdir(tokens[1]);
					if (chdir_exec != 0)
					{
						printf("%s: %d: cd: can't cd to %s\n", argv[0], *n_com, tokens[1]);
						(*n_com)++;
						return (2);
					}
					(*n_com)++;
					return (0);
				}
				(*n_com)++;
				home = _getenv(envp, "HOME");
				chdir(home);
				free(home);
				return (0);
			}
		}
	}
	return (1);
}
