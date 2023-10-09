#include "main.h"

/**
 * execute_command - Execute the given command
 * @command: The command to execute
 */

void execute_command(const char *command) {
    char *args[BUFFER_SIZE];
    char *token;
    int i = 0;
    pid_t pid;

    token = strtok(command, " \t\n");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execve(args[0], args, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }
}
