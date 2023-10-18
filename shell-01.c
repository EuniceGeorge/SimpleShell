#include "main.h"

#define MAX_COMMAND_LENGTH 1024

/**
 * displayPrompt - Display the shell prompt "$ ".
 */
void displayPrompt(void)
{
	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}

/**
 * readCommand - Read a command from the user using getline.
 * @command: Buffer to store the command.
 */
void readCommand(char *command)
{
	ssize_t bytesRead = getline(&command, &(size_t){0}, stdin);

	if (bytesRead == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}

/**
 * executeCommand - Execute the given command.
 * @args: A pointer to a pointer representing the command and its arguments.
 */
void executeCommand(const char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], X_OK) == -1)
	{
		if (write(STDERR_FILENO, args[0], strlen(args[0])) == -1 ||
				write(STDERR_FILENO, ": command not found\n", 20) == -1)
		{
			perror("write");
		}
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
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			dprintf(STDOUT_FILENO, "Exit status: %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			dprintf(STDOUT_FILENO, "Terminated by signal %d\n", WTERMSIG(status));
		}
	}
}

int main(void)
{
	char *command = NULL;

	while (1)
	{
		displayPrompt();
		readCommand(command);

		char *args[MAX_COMMAND_LENGTH / 2 + 1];
		char *token = strtok(command, " ");
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (i > 0)
		{
			executeCommand(args);
		}
	}
	free(command);
	return (0);
}
