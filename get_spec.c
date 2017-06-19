#include "holberton.h"

void get_spec(const char *format, spec_t *spec)
{
	int i = 0;

	i += setflags(format + i, spec);
	i += setwidth(format + i, spec);
	i += setprec(format + i, spec);
	i += setlength(format + i, spec);
	i += settype(format + i, spec);
	spec->stride = i;
}
