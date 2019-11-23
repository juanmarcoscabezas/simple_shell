#include "shell.h"

/**
 * execute_commands -  Execute commands
 * Description: Function that execute commands
 * @cp_argv: Copy of the original argv (the name of the executable)
 * @argv: Params
 * @envp: Enviroment params
 * @n_com: the number of commands given until this point.
 * Return: 1
 */
int execute_commands(char *cp_argv[], char *argv[], char *envp[], int *n_com)
{
	int status, is_accessible, tmp, built_in_result;
	pid_t pid;
	char *path, *com_cpy;

	/* Check built-in functions */
	built_in_result = built_in(cp_argv, argv, envp, n_com);
	if (built_in_result != 1)
	{
		(*n_com)++;
		return (built_in_result);
	}
	/* Check if the file exists */
	is_accessible = access(argv[0], F_OK);
	/* If not accessible try to find in PATH */
	if (is_accessible == -1)
	{
		path = _getenv(envp);
		com_cpy = argv[0];
		argv[0] = check_access(path, argv[0]);
		if (argv[0] == NULL)
		{
			tmp = *n_com;
			dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", cp_argv[0], tmp, com_cpy);
			(*n_com)++;
			if (path)
				free(path);
			return (127);
		}
	}
	if (path)
		free(path);
	(*n_com)++;
	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, envp);
		exit(0);
	}
	else
		wait(&status);
	free(argv[0]);
	return (0);
}
