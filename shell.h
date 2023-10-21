#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

/* get_line function */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
char *_strcpy(char *dest, char *src);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* string operation */
int _strcmp(char *s1, char *s2);
char *_strdup(const char *s);
int _strlen(const char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);

void display_prompt(void);
void execute_command(char *full_path, char **cmd);
char *filecheck(char *str);
char *find_command_path(const char *cmd, char **path_list, int num_paths);
void free_command(char **cmd);
void handle_exit_command(char **cmd);
int is_builtin_command(char *cmd);
char **parse_input(char *input);
void print_environment(void);
int set_environment_variable(char *variable, char *value);
int unset_environment_variable(char *variable);



#endif
