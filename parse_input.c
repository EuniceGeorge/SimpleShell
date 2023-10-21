#include "shell.h"

/**
 * parse_input - Tokenizes the input line to separate command and arguments.
 *
 * @input: The input line.
 * return: An array of strings containing the command and its arguments.
 */
char **parse_input(char *input)
{
	char **tokens = NULL;
	char *token;
	const char *delimiter = " \t\n";
	int token_count = 0;
	
	tokens = (char **)malloc(sizeof(char *));
	
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

    token = strtok((char *)input, delimiter);

    while (token != NULL)
    {
        tokens[token_count] = strdup(token);

        if (tokens[token_count] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        token_count++;

        tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
        if (tokens == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, delimiter);
    }

    tokens[token_count] = NULL;

    return tokens;
}

