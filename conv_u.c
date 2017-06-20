#include "holberton.h"

/**
 * conv_u - function to print formatted unsigned integer
 * @spec: struct containing information on formatting of unsigned int
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_u(spec_t *spec, va_list ap)
{
	char s[20], pad;
	int i, j, tbytes;
	unsigned long int n = 0;

	if (spec->length == 'l')
		n = va_arg(ap, unsigned long int);
	else
		n = va_arg(ap, unsigned int);
	i = 0;
	do {
		s[i] = (n % 10) + '0';
		n /= 10;
		++i;
	} while (n);
	s[i] = '\0';
	j = spec->width - i;
	tbytes = 0;
	if (spec->flags & PLUS_FLAG)
		write(1, "+", 1), --j, ++tbytes;
	else if (spec->flags & SPACE_FLAG)
		write(1, " ", 1), --j, ++tbytes;
	if (spec->flags & JUST_FLAG)
	{
		while (--i >= 0)
			write(1, s + i, 1), ++tbytes;
		while (--j >= 0)
			write(1, " ", 1), ++tbytes;
	}
	else
	{
		pad = (spec->flags & ZERO_FLAG ? '0' : ' ');
		while (--j >= 0)
			write(1, &pad, 1), ++tbytes;
		while (--i >= 0)
			write(1, s + i, 1), ++tbytes;
	}
	return (tbytes);
}
