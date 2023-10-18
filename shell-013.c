#include "main.h"

/**
 * print_aliases - Print all defined aliases
 * @aliases: Array of aliases
 * @alias_count: Number of aliases in the array
 */
void print_aliases(Alias *aliases, int alias_count)
{
	int i;

	for (i = 0; i < alias_count; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * find_alias - Find an alias by name
 * @aliases: Array of aliases
 * @alias_count: Number of aliases in the array
 * @name: The name of the alias to find
 * Return: Pointer to the Alias structure if found, NULL otherwise
 */
Alias *find_alias(Alias *aliases, int alias_count, char *name)
{
	int i;

	for (i = 0; i < alias_count; i++)
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
 * @aliases: Array of aliases
 * @alias_count: Number of aliases in the array
 * @name: The name of the alias
 * @value: The value of the alias
 * Return: 0 on success, -1 on failure
 */
int add_alias(Alias *aliases, int *alias_count, char *name, char *value)
{
	Alias *existing_alias = find_alias(aliases, *alias_count, name);

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
		if (*alias_count >= MAX_ALIASES)
		{
			fprintf(stderr, "Alias limit reached\n");
			return (-1);
		}
		aliases[*alias_count].name = strdup(name);
		aliases[*alias_count].value = strdup(value);
		if (aliases[*alias_count].name == NULL ||
				aliases[*alias_count].value == NULL)
		{
			perror("strdup");
			return (-1);
		}
		(*alias_count)++;
	}
	return (0);
}

/**
 * shell_alias - Builtin alias command
 * @aliases: Array of aliases
 * @alias_count: Number of aliases in the array
 * @args: The arguments for the alias command
 * Return: 0 on success, -1 on failure
 */
int shell_alias(Alias *aliases, int alias_count, char *args[])
{
	int i;

	if (args[1] == NULL)
	{
		print_aliases(aliases, alias_count);
		return (0);
	}
	for (i = 1; args[i] != NULL; i++)
	{
		char *name = args[i];
		char *value = strchr(name, '=');

		if (value != NULL)
		{
			*value = '\0';
			value++;

			if (add_alias(aliases, &alias_count, name,
						value) == -1)
			{
				return (-1);
			}
		}
		else
		{
			Alias *alias = find_alias(aliases, alias_count, name);

			if (alias != NULL)
			{
				printf("%s='%s'\n", alias->name, alias->value);
			}
		}
	}
	return (0);
}
