#include "shell.h"
int _strlen(char *s1, char *s2)
{
	int len, i;

	for (len = 0, i = 0; s1[i] != '\0'; len++, i++)
		;
	for (i = 0; s2[i] != '\0'; len++, i++)
		;
	/* Add 2 for '/' and '\0' */
	return (len + 2);
}
/**
 * _strcat - concat 2 strings.
 * @dest: destination string
 * @src: source string
 * Return: char*
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (j = 0; dest[j] != '\0'; j++)
		;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[j + i] = src[i];
	dest[j + i] = '\0';

	return (dest);
}

/* Check if the command exist in one of the $PATH */
char *check_access(char *path, char *command)
{
	char *single_path;
	char *cat_command;
	int status;

	single_path = strtok(path, ":\n");

	while (single_path)
	{
		cat_command = malloc(sizeof(char) * _strlen(single_path, command));
		cat_command = _strcat(cat_command, single_path);
		cat_command = _strcat(cat_command, "/");
		cat_command = _strcat(cat_command, command);
		status = access(cat_command, F_OK);
		
		if (status == 0)
		{
			printf("ADENTRO: %s", cat_command);
			return (command);
		}

		free(cat_command);
		single_path = strtok(NULL, ":\n");
	}
	return (command);
}
