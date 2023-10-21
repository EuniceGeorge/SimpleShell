#include "shell.h"

/**
 * unset_environment_variable - Unsets an environment variable.
 *
 *@variable: The name of the environment variable to unset.
 * Return: 0 on success, -1 on failure.
 */
int unset_environment_variable(char *variable)
{
	if (unsetenv(variable) == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
