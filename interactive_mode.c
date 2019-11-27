#include "shell.h"

/**
 * interactive_mode - function in charge of shell interactive mode.
 * @argv: arguments passed to the shell
 * @envp: enviroment variables passed to the shell
 * @n_com: the number of commands given until this point
 * Return: void
 **/
void interactive_mode(char *argv[], char *envp[], int *n_com)
{
	char *buffer;
	size_t bufsize = 32;
	size_t getline_len;

	while (1)
	{
		buffer = (char *) malloc(bufsize * sizeof(char));
		if (!buffer)
		{
			perror("Error on allocation");
			exit(100);
		}

		dprintf(STDOUT_FILENO, "#cisfun$ ");
		getline_len = getline(&buffer, &bufsize, stdin);
		if (getline_len > 1)
			get_commands(argv, buffer, envp, n_com);
		else
			(*n_com)++;

		free(buffer);
	}
}
