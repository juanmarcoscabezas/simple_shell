#include "shell.h"
/**
 * handle_sig - function that take care of the interrupt signals.
 * @sig: signal integer
 * Return: void
 **/
void handle_sig(int sig)
{
	(void) sig;
	_puts("\n#cisfun$ ");
}
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
	ssize_t getline_len;

	signal(SIGINT, handle_sig);
	while (1)
	{
		buffer = (char *) malloc(bufsize * sizeof(char));
		if (!buffer)
		{
			perror("Error on allocation");
			exit(100);
		}

		_puts("#cisfun$ ");
		getline_len = getline(&buffer, &bufsize, stdin);
		if (getline_len == EOF)
		{
			free(buffer);
			_putchar('\n');
			exit(0);
		}
		if (getline_len > 1)
			get_commands(argv, buffer, envp, n_com);
		else
			(*n_com)++;

		free(buffer);
	}
}
