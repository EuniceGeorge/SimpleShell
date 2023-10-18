#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *line;

	while ((line = _getline()) != NULL)
	{
		printf("Line read: %s\n", line);
		free(line);
	}
	return (0);
}
