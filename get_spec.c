#include "holberton.h"

/**
 * get_spec - function to parse formatting information following
 * a `%' and populate struct `spec' with relevant formatting info
 * @format: format string passed from `_print' with offset to current `%'
 * @spec: pointer to struct to contain formatting information
 */
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
