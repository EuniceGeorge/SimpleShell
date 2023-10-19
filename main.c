#include "main.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char *arguments[MAX_COMMAND_LENGTH];
	char *command, *token;
	int i = 0;

	while (1)
	{
		display_prompt();
		command = custom_getline();

		if (command == NULL)
		{
			printf("\n");
			break;
		}
		if (strlen(command) == 0)
		{
			free(command);
			continue;
		}
		token = strtok(command, " ");

		while (token != NULL)
		{
			arguments[i++] = token;
			token = strtok(NULL, " ");
		}
		arguments[i] = NULL;

		if (strcmp(arguments[0], "exit") == 0)
		{
			printf("Exiting the shell.\n");
			free(command);
			break;
		}
		else if (strcmp(arguments[0], "env") == 0)
		{
			print_environment();
		}
		else
		{
			if (access(arguments[0], X_OK) == 0)
			{
				execute_command(arguments[0]);
			}
			else
			{
				fprintf(stderr, "Error: Command '%s' not found in PATH\n", arguments[0]);
			}
		}
		free(command);
	}
	return (0);
}
