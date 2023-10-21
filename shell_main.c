#include "shell.h"

/**
 * main - Entry point for the simple_shell program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char *input = NULL;
	size_t input_len = 0;
	char *path = getenv("PATH");
	char *token;
	char **path_list = NULL, **cmd;
	int num_paths = 0;

	token = strtok(path, ":");

	while (token != NULL)
	{
		path_list = realloc(path_list, (num_paths + 1) * sizeof(char *));
		if (!path_list || !(path_list[num_paths] = _strdup(token)))
		{
			perror(!path_list ? "realloc" : "_strdup");
				exit(EXIT_FAILURE);
		}
		num_paths++;
		token = strtok(NULL, ":");
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		if (get_line(&input, &input_len, stdin) == -1)
		{
			printf("\n");
			free(input);
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		if (_strcmp(input, "env") == 0)
		{
			print_environment();
			free(input);
			continue;
		}
		cmd = parse_input(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			if (cmd[1] != NULL)
			{
				int status = atoi(cmd[1]);

				free_command(cmd);
				exit(status);
			}
			break;
		} else if (_strcmp(cmd[0], "setenv") == 0)
		{
			if (cmd[1] != NULL && cmd[2] != NULL)
			{
				if (set_environment_variable(cmd[1], cmd[2]) == 0)
					fprintf(stderr, "Environment variable set: %s=%s\n", cmd[1], cmd[2]);
			} else
			{
				fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
			}
		} else if (_strcmp(cmd[0], "unsetenv") == 0)
		{
			if (cmd[1] != NULL)
			{
				if (unset_environment_variable(cmd[1]) == 0)
					fprintf(stderr, "Environment variable unset: %s\n", cmd[1]);
			} else
			{
				fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			}
		} else
		{
			char *full_path = find_command_path(cmd[0], path_list, num_paths);

			if (full_path)
			{
				execute_command(full_path, cmd);
				/*free(full_path);*/
			} else
			{
				printf("Command not found: %s\n", cmd[0]);
			}
			free_command(cmd);
		}
	}
	return (0);
}
