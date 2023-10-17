#include "main.h"

/**
 * process_variables - Process command with variable replacement
 * @command: The command to process
 * @status: The exit status of the previous command
 * @pid: The process ID of the shell
 * @processed_command: Buffer to store the processed command
 */
void process_variables(char *command, int status, pid_t pid,
		char *processed_command)
{
	char *variable = strtok(command, " ");

	while (variable != NULL)
	{
		if (strcmp(variable, "$?") == 0)
		{
			sprintf(processed_command + strlen(processed_command),
					"%d ", status);
		}
		else if (strcmp(variable, "$$") == 0)
		{
			sprintf(processed_command + strlen(processed_command),
					"%d ", pid);
		}
		else
		{
			sprintf(processed_command + strlen(processed_command),
					"%s ", variable);
		}
		variable = strtok(NULL, " ");
	}
	processed_command[strlen(processed_command) - 1] = '\0';
}
