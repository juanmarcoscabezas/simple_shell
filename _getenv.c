#include "shell.h"

/**
 * _getpath - get only the value of PATH form the env
 * @path: get the line to evaluate
 * Return: 0 if the line contains "PATH" - -1 on failure
 */
int _getpath(char *path)
{
	int counter;
	char *cmp = "PATH";

	for (counter = 0; cmp[counter] != '\0'; counter++)
	{
		if (cmp[counter] != path[counter])
			return (-1);
	}
	return (0);
}

/**
 * _getenv - get the entire envp
 * @envp: char * with the entire envp
 * Return: the PATH (NULL if not found)
 */
char *_getenv(char *envp[])
{
	char *envp_aux, *path;
	int counter;

	path = NULL;

	for (counter = 0; envp != NULL && envp[counter] != NULL; counter++)
	{
		if (_getpath(envp[counter]) == 0)
		{
			envp_aux = malloc(sizeof(char) * _strlen(envp[counter]));
			envp_aux = _strcpy(envp_aux, envp[counter]);
			path = strtok(envp_aux, "=");
			path = strtok(NULL, "");
		}
	}
	return (path);
}
