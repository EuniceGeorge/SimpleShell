#include "main.h"

/**
 * shell_cd - Builtin cd command
 * @args: The arguments for the cd command
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char *args[])
{
	char *new_dir;

	if (args[2] != NULL)
	{
		fprintf(stderr, "cd: too many arguments\n");
		return (-1);
	}
	if (args[1] == NULL || args[1][0] == '~')
	{
		new_dir = getenv("HOME");
	}
	else if (args[1][0] == '-')
	{
		new_dir = getenv("OLDPWD");

		if (new_dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (-1);
		}
		printf("%s\n", new_dir);
	}
	else
	{
		new_dir = args[1];
	}
	if (chdir(new_dir) == -1)
	{
		perror("cd");
		return (-1);
	}
	if (setenv("PWD", getcwd(NULL, 0), 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}
