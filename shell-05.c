#include "main.h"

/**
 * isEnvCommand - Check if the command is the env built-in
 * @command: The command to check
 * Return: 1 if it's the env command, 0 otherwise
 */
int isEnvCommand(char *command)
{
	return (strcmp(command, "env") == 0);
}
