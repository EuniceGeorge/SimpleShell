#include "main.h"

/**
 * process_file - Process commands from a file
 * @filename: The name of the file containing commands
 */
void process_file(char *filename)
{
	FILE *file = fopen(filename, "r");
	char command[MAX_COMMAND_LENGTH];
	char *command_tokens[MAX_COMMANDS];

	if (file == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (fgets(command, sizeof(command), file) != NULL)
	{
		size_t len = strlen(command);

		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}
		tokenize_command(command, command_tokens);
		execute_command(command_tokens);
	}
	fclose(file);
}
