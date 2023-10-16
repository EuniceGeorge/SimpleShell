#include <stdio.h>
#include <stdlib.h>

/**
 * shell_setenv - Builtin setenv command
 * @args: The arguments for the setenv command
 * Return: 0 on success, -1 on failure
 */
int shell_setenv(char *args[])
{
	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * shell_unsetenv - Builtin unsetenv command
 * @args: The arguments for the unsetenv command
 * Return: 0 on success, -1 on failure
 */
int shell_unsetenv(char *args[])
{
	if (args[1] == NULL || args[2] != NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}
	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
