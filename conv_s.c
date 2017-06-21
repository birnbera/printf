#include "holberton.h"

/**
 * conv_s - function to print a null-terminated string
 * @spec: struct containing formatting information for `conv_s'
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_s(spec_t *spec, va_list ap)
{
	int tbytes = 0;
	int prec = spec->prec;
	unsigned char *s = va_arg(ap, unsigned char *);

	if (s == NULL)
		return (0);
	if (prec)
		while (*s && prec--)
			write(1, s++, 1), ++tbytes;
	else
		while (*s)
			write(1, s++, 1), ++tbytes;
	return (tbytes);
}
