#include "shell.h"

/**
 * read_file - function
 * @argv: Name of the file
 * Return: actual number of letters it could print
 */
int read_file(char *argv[])
{
	int file, letters = 10;
	char *buffer, *filename = argv[1], n;

	if (filename == NULL)
		return (0);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file);
		return (0);
	}
	n = read(file, buffer, letters);
	if (n == -1)
	{
		free(buffer);
		close(file);
		return (-1);
	}
	n = write(STDOUT_FILENO, buffer, n);
	if (n == -1)
	{
		free(buffer);
		close(file);
		return (-1);
	}
	free(buffer);
	close(file);
	return (n);
}
