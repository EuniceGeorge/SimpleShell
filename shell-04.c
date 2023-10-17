#include "main.h"

/**
 * isExitCommand - Check if the command is the exit built-in
 * @command: The command to check
 * Return: 1 if it's the exit command, 0 otherwise
 */
int isExitCommand(char *command)
{
	return (strcmp(command, "exit") == 0);
}
