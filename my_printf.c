#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	char c;
	int n, i;
	spec_t spec;

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
			get_spec(&spec, format + i);
			n += spec.conv_func(&spec, va_list);
			i += spec.stride;
		}
	}
	return (n);
}
