#include "main.h"

/**
 * shell_execute_logical - Execute commands with logical operators && and ||
 * @commands: Array of command strings
 */
void shell_execute_logical(char *commands[])
{
	int i = 0;
	char *command_tokens[MAX_COMMANDS];
	int and_operator = 1;

	while (commands[i] != NULL)
	{
		tokenize_command(commands[i], command_tokens);

		if (and_operator && command_tokens[0] != NULL)
		{
			execute_command(command_tokens);
		}
		else if (!and_operator && command_tokens[0] != NULL)
		{
			execute_command(command_tokens);
		}
		if (strcmp(commands[i], "&&") == 0)
		{
			and_operator = 1;
		}
		else if (strcmp(commands[i], "||") == 0)
		{
			and_operator = 0;
		}
		i++;
	}
}
