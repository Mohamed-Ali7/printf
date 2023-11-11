#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int print_char_format(va_list ptr);
int print_string_format(va_list ptr);
int _len(char *s);

/**
* _printf - Produces output according to a format.
* @format: Is string contains both text and format specifiers, which are
* placeholders for the values to print
* Return: The number of printed characters
*/

int _printf(const char *format, ...)
{
	int i = 0;
	int j = 0;
	int printed_chars = 0;
	spec_format spec[] = {
		{"c", print_char_format},
		{"s", print_string_format},
		{NULL, NULL}
	};
	va_list listPtr;

	if (format == NULL)
	{
		exit(1);
	}
	va_start(listPtr, format);
	while (format[i] != '\0')
	{
		j = 0;

		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				printed_chars++;
				i += 2;
				continue;
			}
			while (spec[j].specifier != NULL)
			{
				if (*(spec[j].specifier) == format[i + 1])
				{
					printed_chars += spec[j].func(listPtr);
					break;
				}
				if (spec[j + 1].specifier == NULL)
				{
					exit(1);
				}
				j++;
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	va_end(listPtr);
	return (printed_chars);
}

/**
* print_char_format - Prints the _printf function's argument in char format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: void
*/
int print_char_format(va_list ptr)
{
	char c = va_arg(ptr, int);

	write(1, &c, 1);
	return (1);
}

/**
* print_string_format - Prints the _printf function's argument in string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: void
*/
int print_string_format(va_list ptr)
{
	char *str = va_arg(ptr, char *);
	int l;

	if (str == NULL)
	{
		str = "(null)";
	}
	l = _len(str);
	write(1, str, l);
	return (l);
}

/**
* _len - Calculates the length of a string
* @s: Is the string to calcualte its length
* Return: The length of the string (s)
*/

int _len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

