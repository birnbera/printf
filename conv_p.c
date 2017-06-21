#include "holberton.h"

/**
 * conv_p - print out value stored at the pointer
 * @spec: struct containing information on formatting of argument
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_p(spec_t *spec, va_list ap)
{
	char s[65], pad;
	int i, j, tbytes = 0;
	unsigned long int n = 0;

	n = va_arg(ap, unsigned long int);
	i = conv_base(s, 16, n, 'a');
	j = spec->width - i - 2;
	if (spec->flags & JUST_FLAG)
	{
		write(1, "0x", 2), tbytes += 2;
		while (--i >= 0)
			write(1, s + i, 1), ++tbytes;
		while (--j >= 0)
			write(1, " ", 1), ++tbytes;
	}
	else
	{
		pad = (spec->flags & ZERO_FLAG ? '0' : ' ');
		if (spec->flags & ZERO_FLAG)
		{
			write(1, "0x", 2), tbytes += 2;
			while (--j >= 0) /* width is greater than digits */
				write(1, &pad, 1), ++tbytes; /* padding only */
		}
		else
		{
			while (--j >= 0) /* width is greater than digits */
                                write(1, &pad, 1), ++tbytes; /* padding only */
			write(1, "0x", 2), tbytes += 2;
		}
		while (--i >= 0)
			write(1, s + i, 1), ++tbytes;
	}
	return (tbytes);
}
