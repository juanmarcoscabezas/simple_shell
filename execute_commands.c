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
	int execution, status, is_accessible;
	pid_t pid;
	char *path;
	char **directories;

	/* Check if the file exists */
	is_accessible = access(argv[0], F_OK);
	/* If not accessible try to find in PATH */
	if (is_accessible == -1)
	{
		path = _getenv(envp);
		argv[0] = check_access(path, argv[0]);
		printf("ARGV[0] = %s\n", check_access(path, argv[0]));
		/* str_replace(argv[0], check_access(path, argv[0]));*/
	}

	pid = fork();
	if (pid == 0)
	{
		execution = execve(argv[0], argv, envp);

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
