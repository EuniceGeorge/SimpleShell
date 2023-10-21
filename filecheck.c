#include "shell.h"

/*
 * filecheck - it checks if argument passed is in the file
 * @str: it is the argument that is passed
 * Return: it returns null value
 */

char *filecheck(char *str)
{
	DIR *dir = opendir("/bin/");
	struct dirent *entity;
	char *temp, *cats;

	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
		temp = entity->d_name;
			if (strcmp(temp, str) == 0)
		{
			cats = strcat("/bin/", str);
			closedir(dir);
			return (cats);
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
