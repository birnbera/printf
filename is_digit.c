/**
 * _isdigit - checks whether character `c' is a digit
 * @c: character to check
 *
 * Return: 1 if true, 0 if false
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
