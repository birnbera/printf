#include "holberton.h"
#include <stdlib.h>

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
	char *s = va_arg(ap, char *);

	if (s == NULL)
		s = "(null)";
	if (prec >= 0)
		while (*s && prec--)
			writetobuf(s++, 1);
	else
		while (*s)
			writetobuf(s++, 1);
	return (tbytes);
}
