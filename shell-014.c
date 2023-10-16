#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

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
 * process_variables - Process command with variable replacement
 * @command: The command to process
 * @status: The exit status of the previous command
 * @pid: The process ID of the shell
 * @processed_command: Buffer to store the processed command
 */
void process_variables(char *command, int status, pid_t pid,
		char *processed_command)
{
	char *variable = strtok(command, " ");

	while (variable != NULL)
	{
		if (strcmp(variable, "$?") == 0)
		{
			sprintf(processed_command + strlen(processed_command),
					"%d ", status);
		}
		else if (strcmp(variable, "$$") == 0)
		{
			sprintf(processed_command + strlen(processed_command),
					"%d ", pid);
		}
		else
		{
			sprintf(processed_command + strlen(processed_command),
					"%s ", variable);
		}
		variable = strtok(NULL, " ");
	}
	processed_command[strlen(processed_command) - 1] = '\0';
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
			printf("Command exited with status %d\n",
					WEXITSTATUS(status));
		}
		else
		{
			printf("Command terminated abnormally\n");
		}
	}
}
