#include "main.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char *command, *token;

    while (1)
    {
        display_prompt();

	command = custom_getline();

        if (command == NULL)
        {
            /* Handle end-of-file condition (Ctrl+D)*/
            printf("\n");
            break;
        }
	/* Check for empty command*/
        if (strlen(command) == 0)
        {
            /* Prompt again*/
            free(command);
            continue;
        }

        /* Tokenize the command and arguments*/
        token = strtok(command, " ");
        char *arguments[MAX_COMMAND_LENGTH];
        int i = 0;

        while (token != NULL)
        {
            arguments[i++] = token;
            token = strtok(NULL, " ");
        }

        /*NULL-terminate the arguments array*/
        arguments[i] = NULL;
	 /* Check if the command is a built-in*/
        if (strcmp(arguments[0], "exit") == 0)
        {
            printf("Exiting the shell.\n");
            free(command);
            break;
        }
        else if (strcmp(arguments[0], "env") == 0)
        {
            print_environment();
        }
        else
        {
            /* Execute the command if it exists in the PATH*/
            if (access(arguments[0], X_OK) == 0)
            {
                execute_command(arguments[0], arguments);
            }
            else
            {
                fprintf(stderr, "Error: Command '%s' not found in PATH\n", arguments[0]);
            }
        }
	free(command);
    }

    return 0;
}
