void get_spec(char *format, spec_t *spec)
{
	char c;
	int i;

	i = 0;
	i += setflags(format + i, spec);
	i += setwidth(format + i, spec);
	i += setprec(format + i, spec);
	i += setlength(format + i, spec);
	i += settype(format + i, spec);
	spec->stride = i;
}
