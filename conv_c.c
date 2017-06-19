#include <stdarg.h>

int conv_c(spec_t *spec, va_list ap)
{
	int i, tbytes;
	char c = va_arg(ap, char);

	i = spec->length;
	if (spec->flags & JUST_FLAG)
	{
		write(1, &c, 1), ++tbytes;
		while (--i >= 0)
			write(1, " ", 1), ++tbytes;
	}
	else
	{
		while (--i >= 0)
			write(1, " ", 1), ++tbytes;
		write(1, &c, 1), ++tbytes;
	}
	return (tbytes);
}
