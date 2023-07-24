#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_reverse - Prints reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(null)";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char b = str[i];

		write(1, &b, 1);
		count++;
	}
	return (count);
}
