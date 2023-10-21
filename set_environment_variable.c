#include "shell.h"

/**
 * set_environment_variable - Sets or modifies an environment variable.
 *
 * @variable: The name of the environment variable.
 * @value: The value to assign to the environment variable.
 * return: 0 on success, -1 on failure.
 */
int set_environment_variable(char *variable, char *value)
{
	if (setenv(variable, value, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}
