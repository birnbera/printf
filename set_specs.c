#include "holberton.h"

/**
 * setflags - parse characters immediately following `%' and set `spec->flags'
 * bitfield depending on flags encountered
 * @format: format string from `_print' with offset to current' `%'
 * @spec: pointer to struct to contain formatting information
 *
 * Return: Number of characters parsed as flags
 */
int setflags(const char *format, spec_t *spec)
{
	int i = 0;
	char c;

	while ((c = format[i]))
	{
		switch (c)
		{
		case '-':
		{
			spec->flags |= JUST_FLAG;
			break;
		}
		case '+':
		{
			spec->flags |= PLUS_FLAG;
			break;
		}
		case ' ':
		{
			spec->flags |= SPACE_FLAG;
			break;
		}
		case '0':
		{
			spec->flags |= ZERO_FLAG;
			break;
		}
		default:
			return (i);
		}
		++i;
	}
	return (i);
}

/**
 * setwidth - parse characters following flags, if any, and
 * set within width variable within struct `spec'
 * @format: format string passed from `_print' with offset to `%' + any flags
 * @spec: pointer to struct to contain formatting info used for printing
 *
 * Return: Number of characters processed as width
 */
int setwidth(const char *format, spec_t *spec)
{
	int i = 0, w = 0;
	char c;

	while ((c = format[i]) && _isdigit(c))
	{
		w *= 10;
		w += (c - '0') % 10;
		++i;
	}
	spec->width = w;
	return (i);
}

/**
 * setprec - parse characters following flags and width as precision
 * and set within `prec' variable of struct `spec'
 * @format: format string passed from `_print' with offset to `%' + flags/width
 * @spec: pointer to struct to contain formatting info for printing
 *
 * Return: Number of characters processed as precision
 */
int setprec(const char *format, spec_t *spec)
{
	char c;
	int i = 0, p = 0;

	if (format[i] == '.')
	{
		++i;
		while ((c = format[i]) && _isdigit(c))
		{
			p *= 10;
			p += (c - '0') % 10;
			++i;
		}
	}
	spec->prec = p;
	return (i);
}
/**
 * setlength - parse characters following flags, width, and precision as length
 * and set in `length' variable with struct `spec'
 * @format: format string passed from `_print' with current offset from `%'
 * @spec: pointer to struct `spec' containing info for printing
 *
 * Return: Number of characters interpreted as length
 */
int setlength(const char *format, spec_t *spec)
{
	if (*format == 'l')
	{
		spec->length = 'l';
		return (1);
	}
	spec->length = '\0';
	return (0);
}
/**
 * settype - after parsing flag, width, precision, and length fields,
 * loop through list of valid specifiers and set appropriate string
 * conversion function in struct `spec'
 * @format: format string passed from `_print' with current offset from `%'
 * @spec: pointer to struct `spec' containing info for printing
 *
 * Return: Number of characters processed as format specifiers
 */
int settype(const char *format, spec_t *spec)
{
	int i;
	char c = *format;
	conv_func_t conv_funcs[] = {
			{'%', conv_pc},
			{'i', conv_i},
			{'d', conv_i},
			{'u', conv_u},
			{'b', conv_b},
/*
 *			{'f', conv_f},
 *			{'e', conv_e},
 *			{'E', conv_E},
 */
			{'x', conv_x},
			{'X', conv_X},
			{'o', conv_o},
			{'s', conv_s},
			{'S', conv_S},
			{'c', conv_c},
/*
 *			{'p', conv_p},
 *			{'a', conv_a},
 *			{'A', conv_A},
 */
			{'\0', NULL}
		};
	i = 0;
	while (conv_funcs[i].symbol)
	{
		if (conv_funcs[i].symbol == c)
		{
			spec->func = conv_funcs[i].func;
			return (1);
		}
		++i;
	}
	spec->func = NULL;
	return (0);
}
