#include "holberton.h"

char buf[BUF_SIZE];
unsigned int buf_idx = 0;

/**
 * writetobuf - write chars from `c' to externally linked `buf' starting
 * at externally defined `buf_idx'.
 * @c: string or address of character to add to `buf'
 * @n: number of characters to add to `buf' from `c'
 *
 * Return: Number of characters written as specified by `n'
 */
unsigned int writetobuf(char *c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && buf_idx < BUF_SIZE - 1; ++i, ++buf_idx)
	{
		buf[buf_idx] = c[i];
		buf[buf_idx + 1] = '\0';
	}
	return (n);
}
