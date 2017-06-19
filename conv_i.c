#include "holberton.h"
#define ABS(x) ((x) < 0 ? -1 * (x) : (x))

/**
 * conv_i - function to format printing a decimal integer
 * @spec: struct containing information for formatting decimal
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_i(spec_t *spec, va_list ap)
{
	char s[20], pad;
	int i, j, sign, tbytes;
	long int n;

	if (spec->length == 'l')
		n = va_arg(ap, long int);
	else
		n = va_arg(ap, int);
	sign = (n < 0 ? -1 : 1);
	i = 0;
	do {
		s[i] = ABS(n % 10) + '0';
		n /= 10;
		++i;
	} while (n);
	s[i] = '\0';
	j = spec->width - i;
	tbytes = 0;
	if (sign < 0)
		write(1, "-", 1), --j, ++tbytes;
	else if (spec->flags & PLUS_FLAG)
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
