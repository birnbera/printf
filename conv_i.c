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
	long int n = 0;

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
		writetobuf("-", 1);
	else if (spec->flags & PLUS_FLAG)
		writetobuf("+", 1);
	else if (spec->flags & SPACE_FLAG)
		writetobuf(" ", 1);
	if (spec->flags & JUST_FLAG)
	{
		while (--i >= 0)
			writetobuf(s + i, 1);
		while (--j >= 0)
			writetobuf(" ", 1);
	}
	else
	{
		pad = (spec->flags & ZERO_FLAG ? '0' : ' ');
		while (--j >= 0)
			writetobuf(&pad, 1);
		while (--i >= 0)
			writetobuf(s + i, 1);
	}
	return (tbytes);
}
