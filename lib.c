#include "shell.h"

/**
 * _atoi - String to int
 * Description: This function convert from string to int
 * @s: Pointer that contains the numbers
 * Return: string to int
 */
int _atoi(char *s)
{
	int counter, sign;
	unsigned int number;

	sign = 1;
	counter = 0;
	number = 0;


	while ((s[counter] < '0' || s[counter] > '9') && (s[counter] != '\0'))
	{
		if (s[counter] == '-')
			sign *= -1;
		counter++;
	}
	while ((s[counter] >= '0') && (s[counter] <= '9'))
	{
		number = number * 10 + (s[counter] - '0');
		counter++;
	}
	return (number * sign);
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

/**
 * _memcpy - Copies memory area
 * Description: This function copies @n bytes from memory
 * area @src to memory area @dest
 * @dest: Pointer that store new memory area values
 * @src: Pointer taht cointas memory area values
 * @n: Bytes of memory area to copy
 * Return: The @dest with @src memory area values
 */
void _memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
}

/**
 * _realloc - Reallocates a memory block
 * Description: This function reallocates a memmory block
 * using malloc and free
 * @ptr: The pointer allocated
 * @old_size: Size in bytes of allocated space for @ptr
 * @new_size: New size in bytes for @ptr
 * Return: A pointer to the created array
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *a;

	if (ptr == NULL)
	{
		a = malloc(new_size);
		if (a == NULL)
			return (NULL);
		return (a);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	a = malloc(new_size);
	if (a == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
		_memcpy(a, ptr, old_size);
	else
		_memcpy(a, ptr, new_size);
	free(ptr);
	return (a);
}
