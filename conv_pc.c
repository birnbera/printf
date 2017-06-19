#include "holberton.h"

int conv_pc(spec_t *spec, va_list ap)
{
	(void)spec;
	(void)ap;
	write(1, "%", 1);
	return (1);
}
