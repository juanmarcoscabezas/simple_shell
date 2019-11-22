#include "shell.h"

/**
 * check_value - Look for the flag of exit
 * Description: This function checks the flag of exit
 * @cp_argv: Copy of passed arguments to main
 * @number: Number to check if is an integer
 * @num_com: Number of commands executed
 * Return: 0 if success, -1 otherwise
 */
int check_value(char *cp_argv[], char *number, int *num_com)
{
	int counter = 0;

	while (number[counter] != '\0')
	{
		if (number[counter] < 48 || number[counter] > 57)
		{
			printf("%s: %d: exit: Illegal number: %s\n", cp_argv[0], *num_com, number);
			return (-1);
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
 * @n_com: Number of commands executed
 * Return: the flag passed to exit, -1 otherwise
 */
int built_in(char *cp_argv[], char *argv[], int *n_com)
{
	if (argv != NULL)
	{
		if (argv[0])
		{
			if (_strcmp(argv[0], "exit") == 0)
			{
				if (argv[1])
				{
					if (check_value(cp_argv, argv[1], n_com) == 0)
						exit(_atoi(argv[1]));
					return (-1);
				}
				exit(0);
			}
		}
	}
	return (0);
}
