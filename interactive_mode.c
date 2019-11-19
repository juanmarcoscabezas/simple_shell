#include "shell.h"

/**
 * interactive_mode - Prints a prompt
 * Description: This function prints a prompt
 * @void:
 * Return:
 */
void interactive_mode(char *envp[], int *number_commands)
{
	char *buffer;
	size_t bufsize = 32;
	size_t getline_len;

	buffer = (char *) malloc(bufsize * sizeof(char));
	if (!buffer)
	{
		perror("Error on allocation");
		exit(100);
	}

	while (1)
	{
	
		printf("($) ");			
		getline_len = getline(&buffer, &bufsize, stdin);
		if (getline_len > 1)
			get_commands(buffer, envp, number_commands);
		else
			(*number_commands)++;
	}
}
