#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10
#define READ_SIZE 1024
#define MAX_COMMANDS 100
#define MAX_ALIASES 50


extern char **environ;

/* Alias Structure */

typedef struct
{
        char *name;
        char *value;
} Alias;

/* Prototype for the functions */

void displayPrompt(void);
void readCommand(char *command);
void executeCommand(const char **args);
void parseCommand(char *command, char **args);
int isExitCommand(char *command);
int isEnvCommand(char *command);
char *_getline(void);
char *readBuffer(void);
void appendToLine(char **line, size_t *line_size, char *buffer, size_t buffer_index);
char *reallocLine(char *line, size_t size);
void nullTerminateLine(char **line, size_t line_size);
void shell_exit(char *args[]);
int shell_setenv(char *args[]);
int shell_unsetenv(char *args[]);
int shell_cd(char *args[]);
void tokenize_command(char *command, char *command_tokens[]);
void execute_command(char *command_tokens[]);
void shell_execute_commands(char *commands[]);
void shell_execute_logical(char *commands[]);
void print_aliases(Alias *aliases, int alias_count);
Alias *find_alias(Alias *aliases, int alias_count, char *name);
int add_alias(Alias *aliases, int *alias_count, char *name, char *value);
int shell_alias(Alias *aliases, int alias_count, char *args[]);
void process_variables(char *command, int status, pid_t pid, char *processed_command);
void remove_comments(char *command, char *processed_command);
void process_file(char *filename);
void tokenizePath(const char *path, char *directories[]);
char *constructCommandPath(const char *directory, const char *command);
void searchAndExecuteCommand(const char *command, char *directories[], char **env);
int exeCommand(const char *command, char **env);
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[], __attribute__((unused)) char *envp[])

#endif /*main_h*/
