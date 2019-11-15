#include "shell.h"

/**
 * main.c - function main entry.
 * Description: main function for our shell
 * @argc: number of arguments pass to the shell
 * @argv: char ** pass to the shell
 * @envp: enviroment pass to the shell
 * Return: 0 on success
 **/
int main(int argc, char *argv[], char *envp[])
{
	int execution;
	char *env = {NULL};
	char *command[] = {"-l", NULL};

	execution = execve("/bin/ls", command, env);

	if (execution == -1)
		perror("Error\n");

	return (0);
}
