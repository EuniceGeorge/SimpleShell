#include "shell.h"

/**
 ** is_builtin_command - Checks if the given command is a built-in command.
 **
 ** @cmd: The command to check.
 ** return 1 if the command is a built-in command, 0 otherwise.
 **/

int is_builtin_command(char *cmd)
{
	return (strcmp(cmd, "exit") == 0 || strcmp(cmd, "env") == 0);
}
