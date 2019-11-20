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
 * _memset - Fills memory
 * Description: This function fills memory with a constant byte @b
 * @s: Pointer to change memory values
 * @b: Byte that gonna fill @s
 * @n: Fill the first @n bytes
 * Return: The @s filled
 */
void _memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
}
