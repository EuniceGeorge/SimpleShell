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
 * executeCommand - Execute the given command
 * @args: A pointer to a pointer
 */
void executeCommand(const char **args)
{
	pid_t pid;

	if (access(args[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		if (execve(args[0], (char *const *)args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			printf("%d\n", WIFEXITED(status));
		}
	}
}
