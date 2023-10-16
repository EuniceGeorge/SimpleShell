#include "main.h"

/**
 * _getline - Custom getline function
 *
 * Return: Pointer to the read line, or NULL on failure or end of file
 */
char *_getline(void)
{
	static char buffer[READ_SIZE];
	static size_t buffer_index;
	static ssize_t bytes_read;
	size_t line_size = 0;
	char *line = NULL;

	while (1)
	{
		if (buffer_index == bytes_read)
		{
			buffer_index = 0;
			bytes_read = read(STDIN_FILENO, buffer, READ_SIZE);

			if (bytes_read == 0)
			{
				if (line_size == 0)
				{
					return (NULL);
				}
				break;
			}
			if (bytes_read == -1)
			{
				perror("read");
				free(line);
				return (NULL);
			}
		}
		while (buffer_index < bytes_read && buffer[buffer_index] != '\n')
		{
			appendToLine(&line, &line_size, buffer, buffer_index);
		}
		if (buffer_index < bytes_read && buffer[buffer_index] == '\n')
		{
			appendToLine(&line, &line_size, buffer, buffer_index);
			break;
		}
	}
	nullTerminateLine(&line, line_size);
	return (line);
}

/**
 * appendToLine - Append a character to the line
 * @line: Pointer to the line
 * @line_size: Pointer to the size of the line
 * @buffer: Buffer containing characters
 * @buffer_index: Index of the character in the buffer
 */
void appendToLine(char **line, size_t *line_size, char *buffer,
		size_t buffer_index)
{
	char *temp = reallocLine(*line, *line_size + 1);

	if (temp == NULL)
	{
		perror("realloc");
		free(*line);
		exit(EXIT_FAILURE);
	}
	*line = temp;
	(*line)[(*line_size)++] = buffer[buffer_index++];
}

/**
 * reallocLine - Reallocate memory for the line
 * @line: Pointer to the line
 * @size: New size of the line
 * Return: Pointer to the reallocated line
 */
char *reallocLine(char *line, size_t size)
{
	return (realloc(line, size));
}

/**
 * nullTerminateLine - Null-terminate the line
 * @line: Pointer to the line
 * @line_size: Size of the line
 */
void nullTerminateLine(char **line, size_t line_size)
{
	char *temp = reallocLine(*line, line_size + 1);

	if (temp == NULL)
	{
		perror("realloc");
		free(*line);
		exit(EXIT_FAILURE);
	}
	*line = temp;
	(*line)[line_size] = '\0';
}
