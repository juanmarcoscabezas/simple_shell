#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string
 * @s: String to print
 * Return:
 */
void _puts(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		_putchar(s[counter]);
		counter++;
	}
}

/**
 * print_number - prints integers
 * Description - This function prints an integer
 * @n: number of # and lines, size of triangle
 * Return:
 */
void print_number(int *n)
{
	int n_copy = *n;
	int divisor = 1;

	if (*n < 0)
	{
		divisor = -divisor;
		_putchar('-');
		while (n_copy < -9)
		{
			n_copy = n_copy / 10;
			divisor = divisor * 10;
		}
		while (divisor < -1)
		{
			_putchar((*n / divisor) % 10 + '0');
			divisor = divisor / 10;
		}
		_putchar((*n % 10) * -1 + '0');
	}
	if (*n >= 0)
	{
		while (n_copy > 9)
		{
			n_copy = n_copy / 10;
			divisor = divisor * 10;
		}
		while (divisor > 1)
		{
			_putchar((*n / divisor) % 10 + '0');
			divisor = divisor / 10;
		}
	_putchar(*n % 10 + '0');
	}
}
