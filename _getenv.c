#include "shell.h"

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

char *_getenv(char *envp[])
{
	char *path;
	int counter;

	path = NULL;

	for (counter = 0; envp != NULL && envp[counter] != NULL; counter++)
	{
		if (_getpath(envp[counter]) == 0)
		{
			path = strtok(envp[counter], "=\n");
			break;
		}
	}
	path = strtok(NULL, "\n");
	return (path);
}
