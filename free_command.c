#include "shell.h"

/**
 * free_command - Frees memory allocated for the command and its arguments.
 *
 * @cmd: The array of strings containing the command and its arguments.
 */
void free_command(char **cmd)
{
	int i = 0;

	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

