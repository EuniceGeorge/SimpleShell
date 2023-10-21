#include "shell.h"
/**
 * execute_command - Execute the command with arguments using execve.
 *
 * @full_path: The full path of the command.
 * @cmd: The command and its arguments as an array.
 */

void execute_command(char *full_path, char **cmd)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(full_path, cmd, NULL) == -1)
		{
			perror("execve");
			free(full_path);
			exit(EXIT_FAILURE);
		}
	} else if (pid < 0)
	{
		perror("fork");
		free(full_path);
		exit(EXIT_FAILURE);
	} else
	{
		int status;

		waitpid(pid, &status, 0);
	}
	free(full_path);
}
