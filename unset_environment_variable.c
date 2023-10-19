#include "main.h"

/**
 * unset_environment_variable - Unset an environment variable
 * @variable: The name of the environment variable
 * Return: 0 on success, -1 on failure
 */
int unset_environment_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr,
				"Error: Unable to unset environment variable %s\n", variable);
		return (-1);
	}
	return (0);
}
