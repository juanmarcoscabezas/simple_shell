#include "shell.h"

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
 * Return: 1
 */
int execute_commands(char *argv[], char *envp[])
{
	static int commands_number = 1;
	int execution, status, is_accessible;
	pid_t pid;
	char *path;
	char *command_cpy;

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
			dprintf(STDERR_FILENO, "hsh: %d: %s: not found\n", commands_number, command_cpy);
			commands_number++;
			return (-1);
		}
	}

	pid = fork();
	if (pid == 0)
	{
		execution = execve(argv[0], argv, envp);
		commands_number++;
		if (execution == -1)
		{
			perror("Error execution\n");
		}
	}
	else if (pid == -1)
	{
		perror("Error on pid\n");
		return (-1);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
