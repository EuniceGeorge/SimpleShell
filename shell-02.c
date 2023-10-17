#include "main.h"

/**
 * parseCommand - Parse the command into arguments
 * @command: The command to parse
 * @args: Array to store the arguments
 */
void parseCommand(char *command, char **args)
{
	int i = 0;

	args[i] = strtok(command, " ");
	while (args[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	args[i] = NULL;
}
