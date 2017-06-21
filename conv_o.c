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
	else if (spec->length == 'h')
		n = (unsigned short int) va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
	i = conv_base(s, 8, n);
	j = spec->width - i;
	if (spec->flags & JUST_FLAG)
	{
		if (spec->flags & HASH_FLAG)
			write(1, "0", 1), ++tbytes, --j;
		while (--i >= 0)
			write(1, s + i, 1), ++tbytes;
		while (--j >= 0)
			write(1, " ", 1), ++tbytes;
	}
	else
	{
		pad = (spec->flags & ZERO_FLAG ? '0' : ' ');
		while (--j > 0)
			write(1, &pad, 1), ++tbytes;
		if (spec->flags & HASH_FLAG)
			write(1, "0", 1), ++tbytes;
		else if (j)
			write(1, &pad, 1), ++tbytes;
		while (--i >= 0)
			write(1, s + i, 1), ++tbytes;
	}
	return (tbytes);
}
