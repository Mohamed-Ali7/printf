#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int free_buffer_if_full(char *buffer, int *buffer_index);

/**
* _printf - Produces output according to a format.
* @format: Is string contains both text and format specifiers, which are
* placeholders for the values to print
* Return: The number of printed characters
*/

int _printf(const char *format, ...)
{
	int j, i, buffer_index = 0, printed_chars = 0;
	spec_format spec[] = {{"c", print_char_format}, {"s", print_string_format},
		{"d", print_int_format}, {"i", print_int_format}, {"b", print_binary_format},
		{"u", print_unsigned_int_format}, {"o", print_octal_format},
		{"x", print_lower_hex_format}, {"X", print_upper_hex_format}, {NULL, NULL}};
	char buffer[BUF_SIZE];
	va_list listPtr;
	char ch;

	if (format == NULL)
		return (-1);
	va_start(listPtr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			if (format[i] == '\0')
				return (-1);
			for (j = 0; spec[j].specifier != NULL; j++)
			{
				if (*(spec[j].specifier) == format[i])
				{
					printed_chars += spec[j].func(listPtr, buffer, &buffer_index);
					break;
				}
				if (spec[j + 1].specifier == NULL)
				{
					ch = format[i - 1];
					printed_chars += add_to_buffer(buffer, &buffer_index, &ch, 1);
					ch = format[i];
					printed_chars += add_to_buffer(buffer, &buffer_index, &ch, 1);
				}
			}
			continue;
		}
		ch = format[i];
		printed_chars += add_to_buffer(buffer, &buffer_index, &ch, 1);
	}
	printed_chars += free_buffer(buffer, &buffer_index);
	va_end(listPtr);
	return (printed_chars);
}

/**
 * free_buffer_if_full - Helper function to check the buffer if full & free it
 * @buffer: Is the buffer to check
 * @buffer_index: Is the current index of the buffer
 * Return: The number of printed characters
 */

int free_buffer_if_full(char *buffer, int *buffer_index)
{
	int i = 0;

	if (*buffer_index == 1024)
	{
		i += free_buffer(buffer, buffer_index);
	}
	return (i);
}
