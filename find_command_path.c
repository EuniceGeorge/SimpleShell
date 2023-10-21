#include "shell.h"

/**
 * find_command_path - finds the full path of command the PATH directories.
 *
 * @cmd: The command name.
 * @path_list: The list of directories to search for the command.
 * @num_paths: The number of directories in path_list.
 * Return: The full path of the command if found, or NULL if not found.
 */
char *find_command_path(const char *cmd, char **path_list, int num_paths)
{
	int i;
	char *full_path = NULL;

	for (i = 0; i < num_paths; i++)
	{
		full_path = malloc(strlen(path_list[i]) + _strlen(cmd) + 2);
		if (!full_path)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", path_list[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
	free(full_path);
}
return (NULL);
}
