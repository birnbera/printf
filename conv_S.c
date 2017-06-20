#include "holberton.h"

/**
 * conv_S - print null-terminated string replacing non-printable characters
 * with '\x' followed by hexidecimal representation of value.
 * (e.g. `\n' --> `\x0A').
 * @spec: struct containing formatting information for `conv_S'
 * @ap: variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_S(spec_t *spec, va_list ap)
{
	int tbytes = 0;
	int prec = spec->prec;
	unsigned char *s = va_arg(ap, unsigned char *);

	if (prec)
		while (*s && prec--)
		{
			if (isprintable(*s))
				write(1, s++, 1), ++tbytes;
			else
				tbytes += write_hex(*s++);
		}
	else
		while (*s)
		{
			if (isprintable(*s))
				write(1, s++, 1), ++tbytes;
			else
				tbytes += write_hex(*s++);
		}
	return (tbytes);
}

/**
 * isprintable - tests whether `c' is an ascii printable character
 * @c: unsigned char to print
 *
 * Return: 1 if true, 0 otherwise
 */
int isprintable(unsigned char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * write_hex - write an unsigned char as a hexidecimal digit of the form
 * `\xNN' (e.g. if `c' == 10, print `\x0A').
 * @c: unsigned char to print
 *
 * Return: Number of bytes printed (4 always)
 */
int write_hex(unsigned char c)
{
	unsigned char s[] = "\\x";

	write(1, s, 2);
	s[1] = c % 16;
	if (s[1] > 9)
		s[1] += 'A' - 10;
	else
		s[1] += '0';
	c /= 16;
	s[0] = c % 16;
	if (s[0] > 9)
		s[0] += 'A' - 10;
	else
		s[0] += '0';
	write(1, s, 2);
	return (4);
}
