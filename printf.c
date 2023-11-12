#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int print_char_format(va_list ptr);
int print_string_format(va_list ptr);
int print_int_format(va_list ptr);
int print_binary_format(va_list ptr);
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
		{"d", print_int_format},
		{"i", print_int_format},
		{"b", print_binary_format},
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
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				printed_chars++;
				i++;
				continue;
			}
			if (format[i] == '\0')
			{
				exit(1);
			}
			while (spec[j].specifier != NULL)
			{
				if (*(spec[j].specifier) == format[i])
				{
					printed_chars += spec[j].func(listPtr);
					break;
				}
				j++;

				if (spec[j].specifier == NULL)
				{
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					printed_chars += 2;
				}
			}
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
* Return: The number of printed characters
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
* Return: The number of printed characters
*/
int print_string_format(va_list ptr)
{
	char *str = va_arg(ptr, void *);
	int length;

	if (str == NULL)
	{
		str = "(null)";
	}
	length = _len(str);
	write(1, str, length);
	return (length);
}

/**
* print_int_format - Prints the _printf function's argument in int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/
int print_int_format(va_list ptr)
{
	int i = va_arg(ptr, int);
	int x = 0;
	unsigned int tmp = i;
	int length = 0;
	char nums[10];

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
		length++;
	}
	while (tmp != 0)
	{
		nums[x] = (tmp % 10) + '0';
		tmp = tmp / 10;
		x++;
		length++;
	}
	while (x >= 1)
	{
		write(1, &nums[x - 1], 1);
		x--;
	}
	return (length);
}

/**
* print_binary_format - Prints the _printf function's argument in int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/

int print_binary_format(va_list ptr)
{
	unsigned int val = va_arg(ptr, unsigned int);
	int length = 0;
	int x = 0;
	char binary[10];

	if (val == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (val > 0)
	{
		binary[x] = (val % 2) + '0';
		val = val / 2;
		x++;
		length++;
	}

	while (x >= 1)
	{
		write(1, &binary[x - 1], 1);
		x--;
	}

	return (length);
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
