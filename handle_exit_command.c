#include "shell.h"

/*
 * handle_exit_command- handles the exit function
 * @cmd: the string to be passed
 */

void handle_exit_command(char **cmd)
{
	int status = 0;

	if (cmd[1] != NULL)
	{
		status = atoi(cmd[1]);
	}
	exit(status);
}
