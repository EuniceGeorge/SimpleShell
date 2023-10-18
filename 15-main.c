#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *command_with_comments = "echo Hello # This is a comment";

	shell_execute(command_with_comments);
	return (0);
}
