#include "main.h"

/**
 * set_environment_variable - Set or modify an environment variable
 * @variable: The name of the environment variable
 * @value: The value to set for the environment variable
 * Return: 0 on success, -1 on failure
 */
int set_environment_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Error: Unable to set environment variable
				'%s'\n", variable);
		return (-1);
	}
	return (0);
}
