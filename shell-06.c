#include "main.h"

/**
 * initializeBuffer - Initialize or reset the buffer variables
 * @index: Pointer to the current index in the buffer
 * @bytesRead: Pointer to the number of bytes read into the buffer
 */
static void initializeBuffer(size_t *index, ssize_t *bytesRead)
{
	*index = 0;
	*bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
}

/**
 * resizeLine - Resize the line buffer
 * @line: Pointer to the line buffer
 * @size: Pointer to the size of the buffer
 * Return: 0 on success, -1 on failure
 */
static int resizeLine(char **line, size_t *size)
{
	*size *= 2;
	*line = realloc(*line, *size);
	return ((*line == NULL) ? -1 : 0);
}

/**
 * my_getline - Read a line from standard input
 * @line: Pointer to a buffer to store the line
 * @size: Size of the buffer
 * Return: Number of characters read (including newline), or -1 on failure
 */
ssize_t my_getline(char **line, size_t *size)
{
	static char buffer[BUFFER_SIZE];
	static size_t index, bytesRead;

	if (index == bytesRead && (initializeBuffer(&index, &bytesRead) ||
				bytesRead <= 0))
	{
		return (-1);
	}
	if (*line == NULL)
	{
		*size = BUFFER_SIZE;

		char *tempLine = malloc(*size);

		if (tempLine == NULL)
		{
			return (-1);
		}
	}

	ssize_t i, j;
	char currentChar;

	for (i = 0, j = index; j < bytesRead && buffer[j] != '\n'; ++i, ++j)
	{
		currentChar = buffer[j];

		if (i >= *size - 1 && resizeLine(line, size) == -1)
		{
			return (-1);
		}

		(*line)[i] = currentChar;
	}
	(*line)[i] = '\0';
	index = j + 1;

	return (i + 1);
}
