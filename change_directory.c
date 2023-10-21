#include "shell.h"

/**
 * change_directory - A function to change directory
 * @path: path to pass
 *
 */


void change_directory(const char *path)
{
	if (chdir(path) == 0)
	{
		char cwd[PATH_MAX];
		if (getcwd(cwd, PATH_MAX))
		{
			setenv("PWD", cwd, 1);
			setenv("OLDPWD", path, 1);
		}
		else
		{
			perror("getcwd");
		}
	}
	else
	{
		perror("cd");
	}
}
