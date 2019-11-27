#include "shell.h"

/**
 * _getpath - get only the value of PATH form the env
 * Description:
 * @path: enviroment variable to check if it's equals to @request_path
 * @request_path: variable to check
 * Return: 0 if the line contains "PATH" - -1 on failure
 */
int _getpath(char *path, char *request_path)
{
	int counter;

	for (counter = 0; request_path[counter] != '\0'; counter++)
	{
		if (request_path[counter] != path[counter])
			return (-1);
	}
	return (0);
}

/**
 * _getenv - get the entire envp
 * Description:
 * @envp: enviroment variables passed to the shell
 * @request_path: path to find in @envp
 * Return: the PATH (NULL if not found)
 */
char *_getenv(char *envp[], char *request_path)
{
	char *envp_aux = NULL, *path = NULL, *path_return = NULL;
	int counter, getpath_result;

	for (counter = 0; envp != NULL && envp[counter] != NULL; counter++)
	{
		getpath_result = _getpath(envp[counter], request_path);

		if (getpath_result == 0)
		{
			if (_strlen(envp[counter]) == _strlen(request_path) + 1)
				return (NULL);
			envp_aux = malloc(sizeof(char) * _strlen(envp[counter]));
			if (!envp_aux)
				return (NULL);
			envp_aux = _strcpy(envp_aux, envp[counter]);
			path = strtok(envp_aux, "=");
			path = strtok(NULL, "");
			path_return = malloc(_strlen(path));
			if (!path_return)
			{
				free(envp_aux);
				return (NULL);
			}
			str_replace(path_return, path);
			free(envp_aux);
			break;
		}
	}
	return (path_return);
}
