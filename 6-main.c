#include "main.h"

/**
* main - Simple shell program
*
* Return: Always 0 on success
*/
int main(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t charsRead;
	
	while ((charsRead = my_getline(&line, &size)) != -1)
	{
		if (charsRead > 1)
		{
			printf("Line read: %s", line);
		}
	}
	free(line);
	return (0);
}
