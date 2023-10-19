#include "main.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int offset;

/**
 * custom_getline - Read a line from stdin into buffer.
 *
 * Return: Pointer to line string on success, NULL on failure.
 */
char *custom_getline(void)
{
	int bytes_read = 0;
	int i = 0;
	char *line;

	while (buffer[i] != '\n' && bytes_read < BUFFER_SIZE)
	{
		if (offset == bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			offset = 0;
		}
		if (bytes_read == -1)
		{
			return (NULL);
		}
		i++;
		offset++;
	}
	buffer[i] = '\0';

	line = malloc(i + 1);

	if (line == NULL)
	{
		return (NULL);
	}
	strcpy(line, buffer);

	offset++;

	return (line);
}
