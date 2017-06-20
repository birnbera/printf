#include "holberton.h"

/**
 * conv_c - function to format printing a single character
 * @spec: struct containing formatting parameters
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_c(spec_t *spec, va_list ap)
{
	int i, tbytes = 0;
	unsigned char c;

	c = (unsigned char) va_arg(ap, int);

	i = spec->length;
	if (spec->flags & JUST_FLAG)
	{
		write(1, &c, 1), ++tbytes;
		while (--i >= 0)
			write(1, " ", 1), ++tbytes;
	}
	else
	{
		while (--i >= 0)
			write(1, " ", 1), ++tbytes;
		write(1, &c, 1), ++tbytes;
	}
	return (tbytes);
}
