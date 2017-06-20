#include "holberton.h"

/**
 * conv_o - convert unsigned int argument to octal representation
 * @spec: struct containing information on formatting of argument
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_o(spec_t *spec, va_list ap)
{
	char s[65], pad;
	int i, j, tbytes = 0;
	unsigned long int n = 0;

	if (spec->length == 'l')
		n = va_arg(ap, unsigned long int);
	else
		n = va_arg(ap, unsigned int);
	i = 0;
	do {
		s[i] = (n % 8) + '0';
		n /= 8;
		++i;
	} while (n);
	s[i] = '\0';
	j = spec->width - i;
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
