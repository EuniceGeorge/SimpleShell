#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *command = "echo $? $$";
	int status = 0;
	pid_t pid = getpid();
	char processed_command[256] = "";

	process_variables(command, status, pid, processed_command);

	char *command_tokens[MAX_COMMANDS];

	tokenize_command(processed_command, command_tokens);
	execute_command(command_tokens);
	return (0);
}
