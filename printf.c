#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
* _printf - Produces output according to a format.
* @format: Is string contains both text and format specifiers, which are
* placeholders for the values to print
* Return: The number of printed characters
*/

int _printf(const char *format, ...)
{
	int j, i, printed_chars = 0;
	spec_format spec[] = {{"c", print_char_format}, {"s", print_string_format},
		{"d", print_int_format}, {"i", print_int_format}, {"b", print_binary_format},
		{NULL, NULL}};
	va_list listPtr;

	if (format == NULL)
		exit(1);
	va_start(listPtr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
			{
				printed_chars += write(1, &format[i], 1);
				continue;
			}
			if (format[i] == '\0')
				exit(1);
			for (j = 0; spec[j].specifier != NULL; j++)
			{
				if (*(spec[j].specifier) == format[i])
				{
					printed_chars += spec[j].func(listPtr);
					break;
				}
				if (spec[j + 1].specifier == NULL)
				{
					printed_chars += write(1, &format[i - 1], 1);
					printed_chars += write(1, &format[i], 1);
				}
			}
			continue;
		}
		printed_chars += write(1, &format[i], 1);
	}
	va_end(listPtr);
	return (printed_chars);
}
