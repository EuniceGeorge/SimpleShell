#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void displayPrompt(void);
void readCommand(char *command);
void parseCommand(char *command, char **args);
void executeCommand(char **args);

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
		executeCommand(args);
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
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);

		perror("$ ");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

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
