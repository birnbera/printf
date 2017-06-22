#include "holberton.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * conv_r - print reversed string
 * @spec: struct containing formatting information for `conv_r'
 * @ap: variable argument list
 *
 * Return: Number of bytes written
 */
int conv_r(spec_t *spec, va_list ap)
{
	int i, j, tbytes = 0;
	int prec = spec->prec;
	char *s = va_arg(ap, char *);

	for (i = 0; s && s[i]; ++i)
		;
	if (spec->flags & JUST_FLAG)
	{
		if (prec >= 0)
		{
			j = spec->width - MIN(prec, i);
			while (--i >= 0 && --prec >= 0)
				writetobuf(s + i, 1);
			while (--j >=0)
				writetobuf(" ", 1);

		}
		else
		{
			j = spec->width - i;
			while (--i >= 0)
				writetobuf(s + i, 1);
			while (--j >= 0)
				writetobuf(" ", 1);
		}
	}
	else
	{
                if (prec >= 0)
                {
                        j = spec->width - MIN(prec, i);
                        while (--j >=0)
                                writetobuf(" ", 1);
                        while (--i >= 0 && --prec >= 0)
                                writetobuf(s + i, 1);

                }
                else
                {
                        j = spec->width - i;
                        while (--j >= 0)
                                writetobuf(" ", 1);
                        while (--i >= 0)
                                writetobuf(s + i, 1);
                }
	}
	return (tbytes);
}
