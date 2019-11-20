#include "shell.h"

/**
 * interactive_mode - function in charge of shell interactive mode.
 * @cp_argv: Copy of the original argv (the name of the executable)
 * @envp: enviroment pass to the shell
 * @number_commands: the number of commands given until this point.
 * Return: void
 **/
void interactive_mode(char *cp_argv[], char *envp[], int *number_commands)
{
	char *buffer;
	size_t bufsize = 32;
	size_t getline_len;

	buffer = (char *) malloc(bufsize * sizeof(char));
	if (!buffer)
	{
		perror("Error on allocation");
		exit(100);
	}

	while (1)
	{

		printf("($) ");
		getline_len = getline(&buffer, &bufsize, stdin);
		if (getline_len > 1)
			get_commands(cp_argv, buffer, envp, number_commands);
		else
			(*number_commands)++;
	}
}
