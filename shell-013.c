#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIASES 10

typedef struct
{
	char *name;
	char *value;
} Alias;

Alias aliases[MAX_ALIASES];

int alias_count = 0;

/**
 * print_aliases - Print all defined aliases
 */
void print_aliases(void)
{
	for (int i = 0; i < alias_count; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * find_alias - Find an alias by name
 * @name: The name of the alias to find
 * Return: Pointer to the Alias structure if found, NULL otherwise
 */
Alias *find_alias(char *name)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			return (&aliases[i]);
		}
	}
	return (NULL);
}

/**
 * add_alias - Add or update an alias
 * @name: The name of the alias
 * @value: The value of the alias
 * Return: 0 on success, -1 on failure
 */
int add_alias(char *name, char *value)
{
	Alias *existing_alias = find_alias(name);

	if (existing_alias != NULL)
	{
		free(existing_alias->value);
		existing_alias->value = strdup(value);

		if (existing_alias->value == NULL)
		{
			perror("strdup");
			return (-1);
		}
	}
	else
	{
		if (alias_count >= MAX_ALIASES)
		{
			fprintf(stderr, "Alias limit reached\n");
			return (-1);
		}
		aliases[alias_count].name = strdup(name);
		aliases[alias_count].value = strdup(value);

		if (aliases[alias_count].name == NULL ||
				aliases[alias_count].value == NULL)
		{
			perror("strdup");
			return (-1);
		}
		alias_count++;
	}
	return (0);
}

/**
 * shell_alias - Builtin alias command
 * @args: The arguments for the alias command
 * Return: 0 on success, -1 on failure
 */
int shell_alias(char *args[])
{
	if (args[1] == NULL)
	{
		print_aliases();
		return (0);
	}
	for (int i = 1; args[i] != NULL; i++)
	{
		char *name = args[i];
		char *value = strchr(name, '=');

		if (value != NULL)
		{
			*value = '\0';
			value++;

			if (add_alias(name, value) == -1)
			{
				return (-1);
			}
		}
		else
		{
			Alias *alias = find_alias(name);

			if (alias != NULL)
			{
				printf("%s='%s'\n", alias->name, alias->value);
			}
		}
	}
	return (0);
}
