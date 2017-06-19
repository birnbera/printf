#include "holberton.h"

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
				write(1, &c, 1);
				++n;
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
