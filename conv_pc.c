#include "holberton.h"

/**
 * conv_pc - function to print a single `%' preceded by a `%'
 * @spec: (unused) struct to format printing of inputs
 * @ap: (unused) variable argument list
 *
 * Return: Number of bytes printed
 */
int conv_pc(spec_t *spec, va_list ap)
{
	(void)spec;
	(void)ap;
	write(1, "%", 1);
	return (1);
}
