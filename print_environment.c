#include "main.h"

/**
 * print_environment - Print the current environment
 */
void print_environment(void)
{
    extern char **environ;

    for (char **env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}
