#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *cd_args[] = {"cd", "~/Documents", NULL};

	if (shell_cd(cd_args) == 0)
	{
		printf("Directory changed successfully.\n");
	}
	return (0);
}
