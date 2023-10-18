#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *alias_args[] = {"alias", "my_alias='ls -l'", "another_alias", NULL};

	if (shell_alias(alias_args) == 0)
	{
		printf("Alias command executed successfully.\n");
	}
	return (0);
}
