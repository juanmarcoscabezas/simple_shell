#include "shell.h"

/**
 * interactive_mode - Prints a prompt
 * Description: This function prints a prompt
 * @void:
 * Return:
 */
void interactive_mode(void)
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char *) malloc(bufsize * sizeof(char));
	if (!buffer)
	{
		perror("Error on allocation");
		exit(100);
	}

	while (1)
	{
	
		printf("($) ");			
		characters = getline(&buffer, &bufsize, stdin);
		get_commands(buffer);
	}
}
