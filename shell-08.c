#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * shell_exit - Built-in exit command with status handling
 * @args: The arguments for the exit command
 */
void shell_exit(char *args[])
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);

		if (status == 0 && args[1][0] != '0')
		{
			fprintf(stderr, "shell: exit: %s: numeric argument\
					 required\n", args[1]);
			exit(EXIT_FAILURE);
		}
	}
	exit(status);
}
