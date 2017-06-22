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
	char s[65], pad;
	int i, j, tbytes = 0;
	unsigned long int n = 0;

	if (spec->length == 'l')
		n = va_arg(ap, unsigned long int);
	else if (spec->length == 'h')
		n = (unsigned short int) va_arg(ap, unsigned int);
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
