#include "shell.h"

/**
 * str_replace - replace a str with a second content
 * @dest: Destination str
 * @src: Source str
 * Return: void
 */
void str_replace(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: Params
 * @envp: Enviroment params
 * @number_commands: the number of commands given until this
 * Return: 1
 */
int execute_commands(char *cp_argv[], char *argv[], char *envp[], int *number_commands)
{
	int execution, status, is_accessible, tmp;
	pid_t pid;
	char *path, *command_cpy;

	/* Check if the file exists */
	is_accessible = access(argv[0], F_OK);
	/* If not accessible try to find in PATH */
	if (is_accessible == -1)
	{
		path = _getenv(envp);
		command_cpy = argv[0];
		argv[0] = check_access(path, argv[0]);
		if (argv[0] == NULL)
		{
			tmp = *number_commands;
			dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", cp_argv[0], tmp, command_cpy);
			(*number_commands)++;
			return (-1);
		}
	}
	(*number_commands)++;
	pid = fork();
	if (pid == 0)
	{
		execution = execve(argv[0], argv, envp);
		if (execution == -1)
			perror("Error execution\n");
	}
	else if (pid == -1)
	{
		perror("Error on pid\n");
		return (-1);
	}
	else
		wait(&status);

	return (0);
}
