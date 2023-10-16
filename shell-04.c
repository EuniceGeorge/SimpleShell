#include "main.h"

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
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			printf("%d\n", WIFEXITED(status));
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
