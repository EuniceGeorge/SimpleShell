#include "main.h"

/**
 * tokenizePath - Tokenizes the PATH variable into an array of directories.
 * @path: The PATH variable string.
 * @directories: An array to store individual directories.
 */
void tokenizePath(const char *path, char *directories[])
{
	char *token;
	int i = 0;

	token = strtok((char *)path, ":");

	while (token)
	{
		directories[i++] = strdup(token);
		token = strtok(NULL, ":");
	}
	directories[i] = NULL;
}

/**
 * constructCommandPath - Constructs the full path of the command.
 * @directory: The directory containing the command.
 * @command: The command name.
 * Return: The constructed command path.
 */
char *constructCommandPath(const char *directory, const char *command)
{
	char *command_path = malloc(strlen(directory) + strlen(command) + 2);

	if (!command_path)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	sprintf(command_path, "%s/%s", directory, command);
	return (command_path);
}

/**
 * searchAndExecuteCommand - Searches for the command in PATH and executes it.
 * @command: The command to be executed.
 * @directories: An array of directories in PATH.
 * @env: The environment variables.
 */
void searchAndExecuteCommand(const char *command, char *directories[],
		char **env)
{
	for (int i = 0; directories[i]; i++)
	{
		char *command_path = constructCommandPath(directories[i], command);

		if (execve(command_path, (char *[]){command, NULL}, env) != -1)
		{
			free(command_path);
			exit(0);
		}
		free(command_path);
	}
	fprintf(stderr, "%s: command not found\n", command);
	exit(127);
}

/**
 * exeCommand - Executes a command using execve after searching in PATH.
 * @command: The command to be executed.
 * @env: The environment variables.
 * Return: The exit status of the command.
 */
int exeCommand(const char *command, char **env)
{
	pid_t child_pid;
	int status;

	if (!command)
	{
		return (-1);
	}
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		char *path = getenv("PATH");
		char *directories[1024];
	}
	if (! path)
	{
		return (-1);

		tokenizePath(path, directories);
		searchAndExecuteCommand(command, directories, env);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
