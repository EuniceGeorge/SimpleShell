#include "main.h"
/**
 * _strlen - function that prints length of a string
 * @r:  string whose length to be printed
 *
 * Return: int length of string
 */
int _strlen(char *r)
{
	int j = 0;

	if (!r)
		return (0);

	while (*r++)
		j++;
	return (j);
}

/**
 * _strcmp -  function that compares of two strangs.
 * @s1:  first string
 * @s2:  second string
 *
 * Return: negative if s1 < s2,
 *	positive if s1 > s2,
 *	zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
