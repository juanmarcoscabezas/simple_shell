#include "shell.h"

/**
 * read_textfile - function
 * @filename: text file
 * @letters: numbber of letters to read and print
 * Return: actual number of letters it could print
 */
int read_file(int argc, char *argv[])
{
	int file;
	char *buffer;
	ssize_t n;
	char *filename = argv[1];
	int letters = 10;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
		return (0);

	buffer = malloc(letters);

	if (buffer == NULL)
		return (0);

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
