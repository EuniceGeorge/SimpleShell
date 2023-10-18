#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *args[] = {"exit", "42", NULL};

	shell_exit(args);
	return (0);
}
