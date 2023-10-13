#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void displayPrompt(void);
void readCommand(char *command);
void parseCommand(char *command, char **args);
void executeCommand(char **args);
int isExitCommand(char *command);
int isEnvCommand(char *command);

/**
 * main - Simple shell program
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		displayPrompt();
		readCommand(command);

		if (command[0] == '\0')
		{
			printf("\n");
			break;
		}
		parseCommand(command, args);

		if (isExitCommand(args[0]))
		{
			break;
		}
		else if (isEnvCommand(args[0]))
		{
			char **env = environ;

			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else
		{
			executeCommand(args);
		}
	}
	return (0);
}

/**
 * displayPrompt - Display the shell prompt
 */
void displayPrompt(void)
{
	printf("$ ");
}

/**
 * readCommand - Read a command from the user
 * @command: Buffer to store the command
 */
void readCommand(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		command[0] = '\0';
	}
	else
	{
		command[strcspn(command, "\n")] = '\0';
	}
}

/**
 * parseCommand - Parse the command into arguments
 * @command: The command to parse
 * @args: Array to store the arguments
 */
void parseCommand(char *command, char **args)
{
	int i = 0;

	args[i] = strtok(command, " ");

	while (args[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	args[i] = NULL;
}

/**
 * executeCommand - Execute the given command with arguments
 * @args: The command arguments
 */
void executeCommand(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("$ ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			printf("\n");
		}
		else
		{
			printf("\n");
		}
	}
}

/**
 * isExitCommand - Check if the command is the exit built-in
 * @command: The command to check
 * Return: 1 if it's the exit command, 0 otherwise
 */
int isExitCommand(char *command)
{
	return (strcmp(command, "exit") == 0);
}

/**
 * isEnvCommand - Check if the command is the env built-in
 * @command: The command to check
 * Return: 1 if it's the env command, 0 otherwise
 */
int isEnvCommand(char *command)
{
	return (strcmp(command, "env") == 0);
}
