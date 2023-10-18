#include "main.h"

/**
 * main - Test getline function.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *line;

	printf("Enter some text:\n");

	line = _getline();

	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = _getline();
	}
	return (0);
}
