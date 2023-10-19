#include "main.h"

/**
 * get_path_dirs - Gets array of PATH dir strings
 * @path: Path string
 *
 * Return: Array of directory strings from path
 */
char **get_path_dirs(char *path)
{
	char **dirs = NULL;
	char *token;
	int i = 0;

	token = strtok(path, ":");

	while (token != NULL)
	{
		dirs = realloc(dirs, sizeof(char *) * ++i);
		dirs[i - 1] = token;
		token = strtok(NULL, ":");
	}
	return (dirs);
}

/**
 * find_command - Locates command in PATH directories
 * @cmd: Command to find
 *
 * Return: Path of command if found, NULL if not
 */
char *find_command(char **cmd)
{
	char *path = getenv("PATH");
	char **dirs = get_path_dirs(path);
	char *dir;
	int i = 0;
	char *cmd_path;

	cmd_path = malloc(1024);

	if (!cmd_path)
	{
		return (NULL);
	}
	while (dirs[i] != NULL)
	{
		dir = dirs[i];
		sprintf(cmd_path, "%s/%s", dir, cmd[0]);

		if (access(cmd_path, X_OK) == 0)
		{
			free(cmd_path);
			return (cmd_path);
		}
		i++;
	}
	return (NULL);
}
