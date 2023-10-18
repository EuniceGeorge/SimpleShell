#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *env[] = {NULL};
	int status = exeCommand("ls", env);

	return ((status == -1) ? 1 : 0);
}
