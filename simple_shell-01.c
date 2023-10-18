#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Simple UNIX command line interpreter
 *
 * Description:
 *   Display a prompt, wait for the user to type a command,
 *   execute the command, and repeat.
 *
 * Return: Always 0.
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_chars;
	char *token;

	while (1)
	{
		printf("$ ");
		read_chars = getline(&token, &read_chars, stdin);
		if (read_chars == -1)
		{
			printf("\n");
			free(token);
			exit(EXIT_SUCCESS);
		}
		token[strlen(token) - 1] = '\0';
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error forking");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(token, NULL, NULL) == -1)
			{
				fprintf(stderr, "%s: command not found\n", token);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
