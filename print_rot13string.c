#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char b;
	char *str;
	unsigned int i, j;
	int count = 0;
	char data in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char data out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(BHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (in[j] == str[i])
			{
				b = out[j];
				write(1, &b, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
