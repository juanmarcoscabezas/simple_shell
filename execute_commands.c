#include "shell.h"

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @argv: Params
 * @envp: Enviroment params
 * Return: 1
 */
int execute_commands(char *argv[], char *envp[])
{
	int execution, status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		execution = execve(argv[0], argv, envp);

		if (execution == -1)
		{
			perror("Error\n");
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
