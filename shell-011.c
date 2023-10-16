#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMANDS 10

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
			printf("Command exited with status %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("Command terminated abnormally\n");
		}
	}
}

/**
 * shell_execute_commands - Execute commands separated by semicolons
 * @commands: Array of command strings
 */
void shell_execute_commands(char *commands[])
{
	int i = 0;
	char *command_tokens[MAX_COMMANDS];

	while (commands[i] != NULL)
	{
		tokenize_command(commands[i], command_tokens);
		execute_command(command_tokens);
		i++;
	}
}
