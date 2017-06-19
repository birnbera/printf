int conv_s(spec_t *spec, va_list ap)
{
	int tbytes = 0;
	int prec = spec->prec;
	char *s = va_arg(ap, char *);

	if (prec)
		while (*s && prec)
			write(1, s, 1), ++tbytes;
	else
		while (*s)
			write(1, s, 1), ++tbytes;
	return (tbytes);
}
