#include "shell.h"

/**
 * _atoi - String to int
 * Description: This function convert from string to int
 * @s: Pointer that contains the numbers
 * Return: string to int
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
 * @argv: Parameter to check built-in
 * Return:
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
