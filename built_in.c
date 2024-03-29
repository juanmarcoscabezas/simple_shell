#include "shell.h"

/**
 * check_exit - Look for the flag of exit
 * Description: This function checks the flag of exit
 * @argv: arguments passed to the shell
 * @num: Number to check if is an integer
 * @n_com: the number of commands given until this point.
 * Return: 0 if success, -1 otherwise
 */
int check_exit(char *argv[], char *num, int *n_com)
{
	int counter = 0;
	char *err_msg;

	while (num[counter] != '\0')
	{
		if (num[counter] < 48 || num[counter] > 57)
		{
			err_msg = "exit: Illegal number";

			_puts(argv[0]);
			_puts(": ");
			print_number(n_com);
			_puts(": ");
			_puts(err_msg);
			_puts(": ");
			_puts(num);
			_putchar('\n');
			return (127);
		}
		counter++;
	}
	return (0);
}

/**
 * check_env - Look for the flag of env
 * Description: This function checks the flag of env
 * @tokens: optiones tokenized from a command
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * Return: 0 if success, -1 otherwise
 */
int check_env(char *tokens[], char *envp[], int *n_com)
{
	int counter = 0;

	if (tokens[1])
	{
		_puts("env: ");
		_puts(tokens[1]);
		_puts(": No such file or directory\n");
		(*n_com)++;
		return (127);
	}
	while (envp[counter])
	{
		_puts(envp[counter]);
		_putchar('\n');
		counter++;
	}
	(*n_com)++;
	return (0);
}

/**
 * check_cd - Look for the flag of cd
 * Description: This function checks the flag of cd
 * @argv: arguments passed to the shell
 * @tokens: optiones tokenized from a command
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * Return: 0 if success, -1 otherwise
 */
int check_cd(char *argv[], char *tokens[], char *envp[], int *n_com)
{
	int chdir_exec;
	char *home;
	char *er_m; /* Error message variable */

	if (tokens[1])
	{
		chdir_exec = chdir(tokens[1]);
		if (chdir_exec != 0)
		{
			er_m = "cd: can't cd to";

			_puts(argv[0]);
			_puts(": ");
			print_number(n_com);
			_puts(": ");
			_puts(er_m);
			_puts(" ");
			_puts(tokens[1]);
			_putchar('\n');
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

/**
 * built_in - Built-ins
 * Description: This function is to check the built-ins
 * @argv: arguments passed to the shell
 * @tokens: optiones tokenized from a command
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point.
 * @lo: last output
 * Return: the flag passed to exit, -1 otherwise
 */
int built_in(char *argv[], char *tokens[], char *envp[], int *n_com, int *lo)
{
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
				if (lo)
					exit(*lo);
				exit(0);
			}
			if (_strcmp(tokens[0], "env") == 0)
			{
				return (check_env(tokens, envp, n_com));
			}
			if (_strcmp(tokens[0], "cd") == 0)
			{
				return (check_cd(argv, tokens, envp, n_com));
			}
		}
	}
	return (1);
}
