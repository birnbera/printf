#include "holberton.h"

/**
 * conv_x - convert unsigned int argument to lower case hex
 * @spec: struct containing information on formatting of argument
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_x(spec_t *spec, va_list ap)
{
	char s[65], pad;
	int i, j, tbytes = 0;
	unsigned long int n = 0;

	if (spec->length == 'l')
		n = va_arg(ap, unsigned long int);
	if (spec->length == 'h')
		n = (unsigned short int) va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
	i = 0;
	do {
		if ((n % 16) < 10)
			s[i] = (n % 16) + '0';
		else
			s[i] = ((n % 16) - 10) + 'a';
		n /= 16;
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
