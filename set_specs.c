#include <holberton.h>

int setflags(char *format, spec_t *spec)
{
	int i = 0;
	char c;

	while ((c = format[i]))
	{
		switch c
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

int setwidth(char *format, spec_t *spec)
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

int setprec(char *format, spec_t *spec)
{
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

int setlength(char *format, spec_t *spec)
{
	if (*format == 'l')
	{
		spec->length = 'l';
		return (1);
	}
       	spec->length = '\0';
	return (0);
}

int settype(char *format, spec_t *spec)
{
	char c = *format;
	conv_func_t conv_funcs[] =
		{
			{'%', conv_pc},
			{'i', conv_i},
			{'u', conv_u},
			{'f', conv_f},
			{'e', conv_e},
			{'E', conv_E},
			{'x', conv_x},
			{'X', conv_X},
			{'o', conv_o},
			{'s', conv_s},
			{'c', conv_c},
			{'p', conv_p},
			{'a', conv_a},
			{'A', conv_A},
			{'\0', NULL}
		};
	while (conv_funcs[i].symbol)
	{
		if (conv_func[i].symbol == c)
		{
			spec->func = conv_func[i].func;
			break;
		}
	}
	return (c != '\0');
}
