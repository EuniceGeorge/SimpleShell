#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		displayPrompt();
		readCommand(command);

		if (command[0] == '\0')
		{
			printf("\n");
			break;
		}
		parseCommand(command, args);

		if (isExitCommand(args[0]))
		{
			break;
		}
		else if (isEnvCommand(args[0]))
		{
			char **env = environ;

			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
	}
	return (0);
}
