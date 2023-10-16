#include "main.h"

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
 * process_file - Process commands from a file
 * @filename: The name of the file containing commands
 */
void process_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	char command[MAX_COMMAND_LENGTH];
	char *command_tokens[MAX_COMMANDS];

	while (fgets(command, sizeof(command), file) != NULL)
	{
		size_t len = strlen(command);

		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}
		tokenize_command(command, command_tokens);
		execute_command(command_tokens);
	}
	fclose(file);
}
