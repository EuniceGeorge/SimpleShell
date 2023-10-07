#include <stdio.h>
#include <unistd.h>

int main()
{
	char *buffer = NULL;
	size_t len = 0;
	
	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("%s\n", buffer);
	}
	return 0;

}
