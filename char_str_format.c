#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_char_format - Prints the _printf function's argument in char format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_char_format(va_list ptr, char *buffer, int *buffer_index)
{
	char c = va_arg(ptr, int);
	int printed_characters = 0;

	printed_characters += add_to_buffer(buffer, buffer_index, c);

	return (printed_characters);
}

/**
* print_string_format - Prints the _printf function's argument in string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_string_format(va_list ptr, char *buffer, int *buffer_index)
{
	char *str = va_arg(ptr, void *);
	int i;
	int printed_characters = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, str[i]);
	}
	return (printed_characters);
}

/**
* print_cus_string_format - Prints the _printf function's argument
* in a custom string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_cus_string_format(va_list ptr, char *buffer, int *buffer_index)
{
	char *str = va_arg(ptr, void *);
	int printed_characters = 0;
	int i = 0;
	char *hex = "0123456789ABCDEF";

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			printed_characters += add_to_buffer(buffer, buffer_index, '\\');
			printed_characters += add_to_buffer(buffer, buffer_index, 'x');
			if (str[i] <= 16)
			{
				printed_characters += add_to_buffer(buffer, buffer_index, '0');
			}
			print_hex_format(hex, (unsigned int) str[i], buffer, buffer_index);
			i++;
		}
		else
		{
			printed_characters += add_to_buffer(buffer, buffer_index, str[i]);
			i++;
		}
	}

	return (printed_characters);
}

/**
* print_rot13_string_format - Prints the _printf function's string argument
* encoded into rot13.
*
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_rot13_string_format(va_list ptr, char *buffer, int *buffer_index)
{
	char *str = va_arg(ptr, char *);
	int i = 0;
	int printed_characters = 0;
	char c;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[i] != '\0')
	{
		c = str[i];
		if ((c >= 'A' && c <= 'Z'))
		{
			if ((c + 13) > 'Z')
			{
				c -= 26;
			}
			c += 13;
		}
		else if ((c >= 'a' && c <= 'z'))
		{
			if ((c + 13) > 'z')
			{
				c -= 26;
			}
			c += 13;
		}
		printed_characters += add_to_buffer(buffer, buffer_index, c);
		i++;
	}
	return (printed_characters);
}

/**
* print_rev_string_format - Prints the _printf function's string argument
* in reveresed
*
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_rev_string_format(va_list ptr, char *buffer, int *buffer_index)
{
	char *str = va_arg(ptr, char *);
	int printed_characters = 0;
	char c;
	int str_len;

	if (str == NULL)
	{
		str = "(null)";
	}
	str_len = _len(str);

	while (str_len >= 1)
	{
		c = str[str_len - 1];

		printed_characters += add_to_buffer(buffer, buffer_index, c);
		str_len--;
	}
	return (printed_characters);
}
