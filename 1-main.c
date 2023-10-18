#include "main.h"

/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 * Return: Exit status
 */
int main(__attribute__((unused)) int argc,
		__attribute__((unused)) char *argv[],
		__attribute__((unused)) char *envp[])
{
	while (1)
	{
		char *command;
		char *commands[MAX_COMMANDS];
		
		displayPrompt();
		
		command = _getline();
		
		if (command == NULL)
		{
			perror("_getline");
			continue;
		}
		if (isExitCommand(command))
		{
			free(command);
			break;
		}
		
		parseCommand(command, commands);
		
		executeCommand((const char **)commands);
		
		free(command);
	}
	return (0);
}
