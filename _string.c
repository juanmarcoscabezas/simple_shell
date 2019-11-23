#include "shell.h"

/**
 * _strcpy - copy an array.
 * @dest: destiny
 * @src: source
 * Return: void.
 */
char *_strcpy(char *dest, char *src)
{
	int i, n;

	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i++] = '\0';
	return (dest);
}

/**
 * _strlen - len of char *
 * @s: String to know the length
 * Return: return 1 more to count the null byte.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i + 1);
}

/**
 * str_replace - replace a str with a second content
 * @dest: Destination str
 * @src: Source str
 * Return: void
 */
void str_replace(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * _strcmp - Compare strings
 * Description: This function compare two strings
 * @string1: First string to compare
 * @string2: Second string to compare
 * Return: @n bytes of @src
 */
int _strcmp(char *string1, char *string2)
{
	char *s1 = string1;
	char *s2 = string2;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s2 > *s1)
			return ((*s2 - *s1) * -1);
		s1++;
		s2++;
	}
	return (0);
}

