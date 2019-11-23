#include "shell.h"

/**
 * check_exit - Look for the flag of exit
 * Description: This function checks the flag of exit
 * @cp_argv: Copy of passed arguments to main
 * @number: Number to check if is an integer
 * @n_com: Number of commands executed
 * Return: 0 if success, -1 otherwise
 */
int check_exit(char *cp_argv[], char *number, int *n_com)
{
	int counter = 0;

	while (number[counter] != '\0')
	{
		if (number[counter] < 48 || number[counter] > 57)
		{
			printf("%s: %d: exit: Illegal number: %s\n", cp_argv[0], *n_com, number);
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
int built_in(char *cp_argv[], char *argv[], char *envp[], int *n_com)
{
	int counter = 0, chdir_exec;

	if (argv != NULL)
	{
		if (argv[0])
		{
			if (_strcmp(argv[0], "exit") == 0)
			{
				if (argv[1])
				{
					if (check_exit(cp_argv, argv[1], n_com) == 0)
						exit(_atoi(argv[1]));
					(*n_com)++;
					return (127);
				}
				exit(0);
			}
			if (_strcmp(argv[0], "env") == 0)
			{
				if (argv[1])
				{
					printf("env: %s: No such file or directory\n", argv[1]);
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
			if (_strcmp(argv[0], "cd") == 0)
			{
				if (argv[1])
				{
					chdir_exec = chdir(argv[1]);
					if (chdir_exec != 0)
					{
						printf("%s: %d: cd: can't cd to %s\n", cp_argv[0], *n_com, argv[1]);
						(*n_com)++;
						return (2);
					}
					return (0);
				}
				(*n_com)++;
				chdir("$HOME");
				return (0);
			}
		}
	}
	return (1);
}
