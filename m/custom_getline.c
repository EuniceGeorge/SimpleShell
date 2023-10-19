#include "main.h"

/**
 * custom_getline - Read a line from the standard input
 * Return: A dynamically allocated string containing the line
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static ssize_t chars_read;
	char *line;
	char *temp;
	size_t line_index;

	if ((ssize_t)buffer_index >= chars_read || buffer_index == 0)
	{
		chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (chars_read <= 0)
		{
			return (NULL);
		}
		buffer_index = 0;
	}
	line = malloc(BUFFER_SIZE);

	if (line == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	line_index = 0;

	while ((ssize_t)buffer_index < chars_read)
	{
		char current_char = buffer[buffer_index++];

		if (current_char == '\n')
		{
			line[line_index] = '\0';
			break;
		}
		line[line_index++] = current_char;

		if (line_index % BUFFER_SIZE == 0)
		{
			temp = realloc(line, line_index + BUFFER_SIZE);

			if (temp == NULL)
			{
				perror("realloc");
				free(line);
				exit(EXIT_FAILURE);
			}
			line = temp;
		}
	}
	return (line);
}