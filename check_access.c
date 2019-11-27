#include "shell.h"

/**
 * _strlen_two_strings - len of two strings.
 * @s1: frist char *
 * @s2: second char *
 * Description: Calculate the len of a string
 * include +1 for an extra '/' and +1 for '\0'
 * Return: len of the two strings
 */
int _strlen_two_strings(char *s1, char *s2)
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
void _strcat(char *dest, char *src)
{
	int i, j;

	for (j = 0; dest[j] != '\0'; j++)
		;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[j + i] = src[i];
	dest[j + i] = '\0';
}

/**
 * check_access - check if have access to the bin.
 * @path: get the PATH of the enviroment
 * @command: the name of the command
 * Description: Check if the command exist in one of the $PATH
 * Return: char*
 */
char *check_access(char *path, char *command)
{
	char *single_path;
	char *cat_command;
	int status, len_two;

	single_path = strtok(path, ":\n");
	while (single_path)
	{
		len_two = _strlen_two_strings(single_path, command);
		cat_command = malloc(sizeof(char) * len_two);
		if (cat_command == NULL)
			return (NULL);
		cat_command[0] = '\0';
		_strcat(cat_command, single_path);
		_strcat(cat_command, "/");
		_strcat(cat_command, command);

		status = access(cat_command, F_OK | X_OK | R_OK);
		if (status == 0)
		{
			return (cat_command);
		}

		free(cat_command);
		single_path = strtok(NULL, ":\n");
	}
	return (NULL);
}
