#include "main.h"

/**
 * tokenize_command - Tokenize a command and store tokens in an array
 * @command: The command to tokenize
 * @command_tokens: Array to store command tokens
 */
void tokenize_command(char *command, char *command_tokens[])
{
	char *token = strtok(command, " ");
	int j = 0;

	while (token != NULL)
	{
		command_tokens[j++] = token;
		token = strtok(NULL, " ");
	}
	command_tokens[j] = NULL;
}

/**
 * remove_comments - Remove comments from a command
 * @command: The command to process
 * @processed_command: Buffer to store the processed command
 */
void remove_comments(char *command, char *processed_command)
{
	char *token = strtok(command, "#");

	if (token != NULL)
	{
		strcpy(processed_command, token);
	}
	else
	{
		processed_command[0] = '\0';
	}
}

/**
 * execute_command - Execute a single command
 * @command_tokens: Array of command tokens
 */
void execute_command(char *command_tokens[])
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
		if (execve(command_tokens[0], command_tokens, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			printf("%d\n", WEXITSTATUS(status));
		}
	}
}

/**
 * shell_execute - Execute a command, handling comments
 * @command: The command to execute
 */
void shell_execute(char *command)
{
	char processed_command[256] = "";

	remove_comments(command, processed_command);

	if (strlen(processed_command) > 0)
	{
		char *command_tokens[MAX_COMMANDS];

		tokenize_command(processed_command, command_tokens);
		execute_command(command_tokens);
	}
}
