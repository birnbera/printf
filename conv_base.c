#include "holberton.h"

/**
 * conv_base - convert int to the base given
 *
 * @s: array of digits
 * @base: the base to convert to
 * @n: int to be converted
 * @hex: denotes lower hex or upper hex
 *
 * Return: length of the array
 */

int conv_base(char *s, int base, unsigned long int n, ...)
{
	int i;
	char hex;
	va_list ap;

	va_start(ap, n);
	hex = (char) va_arg(ap, int);
	i = 0;
	do {
		if ((n % base) < 10)
			s[i] = (n % base) + '0';
		else
			s[i] = ((n % base) - 10) + hex;
		n /= base;
		++i;
	} while (n);

	return (i);
}
