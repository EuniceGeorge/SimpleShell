#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *commands[] = {"ls -l", "&&", "echo Hello World",
		"||", "gcc -o my_program my_program.c", NULL};

	shell_execute_commands(commands);
	shell_execute_logical(commands);
	return (0);
}
