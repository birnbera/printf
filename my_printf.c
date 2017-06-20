#include "holberton.h"

/**
 * _printf - print formatted string to stdout using variable number
 * of arguments
 * @format: format string to specify how to interpret unnamed arguments
 *
 * Return: number of bytes printed to stdout
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char c;
	int n, i;
	spec_t spec;

	va_start(ap, format);
	i = n = 0;
	while ((c = format[i]))
	{
		if (c != '%')
		{
			write(1, &c, 1);
			++n;
			++i;
		}
		else
		{
			get_spec(format + i + 1, &spec);
			if (spec.func == NULL)
			{
				if (format[i + 1])
				{
					write(1, &c, 1);
					++n;
					++i;
					continue;
				}
			}
			n += spec.func(&spec, ap);
			i += spec.stride + 1;
		}
	}
	va_end(ap);
	return (n);
}
