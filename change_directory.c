#include "main.h"

/**
 * change_directory - Change the current working directory
 * @path: The directory to change to
 * Return: 0 on success, -1 on failure
 */
int change_directory(const char *path)
{
	char current_directory[PATH_MAX];

	if (getcwd(current_directory, sizeof(current_directory)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	if (path == NULL || strcmp(path, "~") == 0)
	{
		path = getenv("HOME");
	}
	else if (strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
	}
	if (chdir(path) != 0)
	{
		perror("chdir");
		return (-1);
	}
	if (set_environment_variable("PWD", getcwd(current_directory,
					sizeof(current_directory))) != 0)
	{
		return (-1);
	}
	return (0);
}
