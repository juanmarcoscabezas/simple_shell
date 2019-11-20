#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void get_stdin(char *cp_argv[], char *envp[], int *number_commands);
int read_file(char *argv[]);
int get_commands(char *cp_argv[], char *buffer, char *envp[], int *n_commands);
char *_getenv(char *envp[]);
char *check_access(char *path, char *command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void str_replace(char *dest, char *src);
void interactive_mode(char *cp_argv[], char *envp[], int *number_commands);
int execute_commands(char *cp_argv[], char *argv[], char *envp[], int *n_com);

#endif
