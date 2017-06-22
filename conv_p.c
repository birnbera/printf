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
		writetobuf("0x", 2);
		while (--i >= 0)
			writetobuf(s + i, 1);
		while (--j >= 0)
			writetobuf(" ", 1);
	}
	else
	{
		pad = (spec->flags & ZERO_FLAG ? '0' : ' ');
		if (spec->flags & ZERO_FLAG)
		{
			writetobuf("0x", 2);
			while (--j >= 0) /* width is greater than digits */
				writetobuf(&pad, 1); /* padding only */
		}
		else
		{
			while (--j >= 0) /* width is greater than digits */
                                writetobuf(&pad, 1); /* padding only */
			writetobuf("0x", 2);
		}
		while (--i >= 0)
			writetobuf(s + i, 1);
	}
	return (tbytes);
}
