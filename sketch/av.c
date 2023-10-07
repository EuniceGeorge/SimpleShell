#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
			i++;
	}
	return 0;
}
