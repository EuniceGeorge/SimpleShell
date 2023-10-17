#include "main.h"

/**
 * remove_comments - Remove comments from a command
 * @command: The command to process
 * @processed_command: Buffer to store the processed command
 */
void remove_comments(char *command, char *processed_command)
{
	char *token = strtok(command, "#");

	if (token != NULL)
	{
		strcpy(processed_command, token);
	}
	else
	{
		processed_command[0] = '\0';
	}
}

/**
 * shell_execute - Execute a command, handling comments
 * @command: The command to execute
 */
void shell_execute(char *command)
{
	char processed_command[256] = "";

	remove_comments(command, processed_command);

	if (strlen(processed_command) > 0)
	{
		char *command_tokens[MAX_COMMANDS];

		tokenize_command(processed_command, command_tokens);
		execute_command(command_tokens);
	}
}
