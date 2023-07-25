#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;

	va_list list;

	va_start(list, format);

	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					int j = va_arg(list, int);

					printf("%c\n", j);
					break;
				}
				case 's':
				{
					char *str = va_arg(list, char*);

					printf("%s\n", str);
					break;
				}
				case '%':
					putchar('%');
					break;
				default:
				{
					putchar(format[i]);
				}
					i++;
			}
		}
	}
	va_end(list);
	return (0);
}
