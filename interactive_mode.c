#include "shell.h"

/**
 * verify_tab - Function to verify tabs
 * @command: Command to verify
 * @command_len: Length of the command to verify
 * Return: 0 on success, -1 otherwise
 */
int verify_tab(char *command, ssize_t command_len)
{
	ssize_t counter = 0;

	while (counter < command_len)
	{
		if (command[counter] != '\t' && command[counter] != '\n')
		{
			if (command[counter] != ' ' && command[counter] != '\0')
				return (0);
		}
		counter++;
	}
	return (-1);
}
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
	int last_out = 0;

	signal(SIGINT, handle_sig);
	while (1)
	{
		buffer = (char *) malloc(bufsize * sizeof(char));
		if (!buffer)
		{
			perror("Error on allocation");
			exit(0);
		}

		_puts("#cisfun$ ");
		getline_len = getline(&buffer, &bufsize, stdin);
		if (getline_len == EOF)
		{
			free(buffer);
			_putchar('\n');
			exit(last_out);
		}
		if (getline_len > 1)
		{
			if (verify_tab(buffer, getline_len) == 0)
				last_out = get_commands(argv, buffer, envp, n_com, &last_out);
			else
				(*n_com)++;
		}
		else
			(*n_com)++;

		free(buffer);
	}
}
