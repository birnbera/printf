#include "holberton.h"

/**
 * conv_r - print reversed string
 * @spec: struct containing formatting information for `conv_r'
 * @ap: variable argument list
 *
 * Return: Number of bytes written
 */
int conv_r(spec_t *spec, va_list ap)
{
	int i, tbytes = 0;
	int prec = spec->prec;
	unsigned char *s = va_arg(ap, unsigned char *);

	if (!prec)
		prec = -1;
	for (i = 0; s[i] && prec; ++i, --prec)
		;
	--i;
	if (prec)
		while (s[i])
			write(1, s + i--, 1), ++tbytes;
	return (tbytes);
}
