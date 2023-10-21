#include "shell.h"

/*
 * handle_cd - A command to handle command
 * @cmd: the command to be pased
 * *
 */
void handle_cd(char **cmd)
{
	if (cmd[1] == NULL || _strcmp(cmd[1], "~") == 0)
	{
		char *home = getenv("HOME");
		if (home)
		{
			change_directory(home);
		}
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		char *previous_dir = getenv("OLDPWD");
		if (previous_dir)
		{
			change_directory(previous_dir);
		}
		else
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
		}
	}
	else
	{
		change_directory(cmd[1]);
	}
}
