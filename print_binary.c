#include "main.h"
#include <stdarg.h>

/**
 * print_binary - Prints an unsigned number
 * @types: the list of the arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j, k, sum;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	i = va_arg(types, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	b[0] = i / j;
	for (k = 1; k < 32; k++)
	{
		j /= 2;
		b[k] = (i / j) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += b[k];
		if (sum || k == 31)
		{
			char v = '0' + b[k];

			write(1, &v, 1);
			count++;
		}
	}
	return (count);
}
