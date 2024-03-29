#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void get_stdin(char *argv[], char *envp[], int *number_commands);
int read_file(char *argv[], char *envp[], int *number_commands);
int get_commands(char *argv[], char *buf, char *en[], int *n_cmds, int *lo);
char *_getenv(char *envp[], char *request_path);
char *check_access(char *path, char *command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void str_replace(char *dest, char *src);
void interactive_mode(char *argv[], char *envp[], int *number_commands);
int exec_cmds(char *argv[], char *tokens[], char *envp[], int *n_com, int *lo);
void _memset(char *s, char b, unsigned int n);
int built_in(char *argv[], char *tokens[], char *envp[], int *n_com, int *lo);
int _strcmp(char *string1, char *string2);
int _atoi(char *s);
void _puts(char *s);
int _putchar(char c);
void print_number(int *n);
int verify_tab(char *command, ssize_t command_len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
