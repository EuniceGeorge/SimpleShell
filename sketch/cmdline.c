#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char *buffer = NULL;
	size_t line = 0;
	char *token;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &line, stdin);
		
		token = strtok(buffer " ");

	}
}

