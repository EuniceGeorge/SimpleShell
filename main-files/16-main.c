#include "main.h"

/**
* main - Simple shell program
*
* @argc: Arguement Count
* @argv: Arguement Vector
* Return: Always 0 on success
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	return (0);
}
