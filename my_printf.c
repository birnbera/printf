#include "holberton.h"

char buf[BUF_SIZE];
int buf_idx = 0;

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

	if (format == NULL)
		return (0);
	va_start(ap, format);
	i = n = 0;
	while ((c = format[i]))
	{
		if (c != '%')
		{
			i += write(1, &c, 1);
			++n;
		}
		else
		{
			get_spec(format + i + 1, &spec);
			if (spec.func == NULL)
			{
				if (format[i + spec.stride + 1] == '\0')
					break;
				n += write(1, &c, 1);
				++i;
				continue;

			}
			n += spec.func(&spec, ap);
			i += spec.stride + 1;
		}
	}
	va_end(ap);
	return (n);
}
