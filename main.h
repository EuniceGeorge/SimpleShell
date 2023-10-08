#ifndef MAIN_H
#define MAIN_H

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

/*prototype for the functions*/
void display_prompt();
void execute_command(const char *command, char *const arguments[]);
void print_environment(void);
char *custom_getline(void);
int set_environment_variable(const char *variable, const char *value);
int unset_environment_variable(const char *variable);
int change_directory(const char *path);
void execute_commands(const char *command);
void alias_command(char *const arguments[]);
void replace_variables(const char *input, char *output);
void remove_comments(const char *input, char *output);


typedef struct Alias
{
    char *name;
    char *value;
    struct Alias *next;
} Alias;

/*string operations*/



#endif
