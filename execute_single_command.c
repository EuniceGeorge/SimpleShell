#include "shell.h"

/*
 * execute_single_command - A function to execute a single command
 * @command: the command passed
 *
 */

void execute_single_command(char *command)
{
	 char *input = NULL;
    char **path_list = NULL;
    int num_paths = 0;
    char **cmd = parse_input(command);

    if (cmd[0] != NULL)
    {
	     if (_strcmp(input, "exit") == 0)
                {
                        free(input);
                }
                if (_strcmp(input, "env") == 0)
                {
                        print_environment();
                        free(input);
                }
                if (_strcmp(cmd[0], "exit") == 0)
                {
                        if (cmd[1] != NULL)
                        {
                                int status = atoi(cmd[1]);

                              free_command(cmd);
                                exit(status);
                        }
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
                } else if (_strcmp(cmd[0], "cd") == 0)
                {
                        handle_cd(cmd);
                }
                else
                {
                       char *full_path = find_command_path(cmd[0], path_list, num_paths);

                        if (full_path)
                        {
                                execute_command(full_path, cmd);
                        } else
                        {
                                printf("Command not found: %s\n", cmd[0]);
                        }
	                     free_command(cmd);
                }
        }
}
