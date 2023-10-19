#include "main.h"

/**
 * validate_exit_status - Validates exit status argument
 * @arg: Argument to validate
 *
 * Return: Exit status as int, or -1 on error
*/
int validate_exit_status(char *arg)
{
	int status = 0;

	if (arg != NULL)
	{
		status = atoi(arg);

		if (status == 0 && arg[0] != '0')
		{
			fprintf(stderr, "Numeric argument required\n");
			return (-1);
		}
	}
	return (status);
}

/**
 * shell_exit - Exits shell with given status
 * @args: Arguments array
 *
 * Return: Exit status
*/
int shell_exit(char **args)
{
	int status = validate_exit_status(args[1]);

	if (status == -1)
	{
		return (1);
	}
	status &= 0xFF;
	return (status);
}
