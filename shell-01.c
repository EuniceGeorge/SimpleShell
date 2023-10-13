#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void displayPrompt(void);
void readCommand(char *command);
void executeCommand(const char *command);

/**
 * main - Simple shell program
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		displayPrompt();
		readCommand(command);

		if (command[0] == '\0')
		{
			printf("\n");
			break;
		}
		executeCommand(command);
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
 * executeCommand - Execute the given command
 * @command: The command to execute
 */
void executeCommand(const char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(command, command, (char *)NULL);

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

