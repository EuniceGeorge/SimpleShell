#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *setenv_args[] = {"setenv", "MY_VAR", "my_value", NULL};
	char *unsetenv_args[] = {"unsetenv", "MY_VAR", NULL};

	if (shell_setenv(setenv_args) == 0)
	{
		printf("Environment variable set successfully.\n");
	}
	if (shell_unsetenv(unsetenv_args) == 0)
	{
		printf("Environment variable unset successfully.\n");
	}
	return (0);
}
