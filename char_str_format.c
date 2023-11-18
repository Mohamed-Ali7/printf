#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* char_format - Prints the _printf function's argument in char format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int char_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	char c = va_arg(ptr, int);
	int printed_characters = 0;
	int i;

	(void) (flag);
	(void) (prec);

	for (i = 0; i < width - 1; i++)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, ' ');
	}

	printed_characters += add_to_buffer(buffer, buffer_index, c);

	return (printed_characters);
}

/**
* string_format - Prints the _printf function's argument in string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int string_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	char *str = va_arg(ptr, char *);
	int i, len;
	int printed_characters = 0;

	(void) (flag);

	if (str == NULL)
	{
		if (prec > 0 && prec < 6)
		{
			return (0);
		}
		str = "(null)";
	}

	len = _len(str);
	if (prec > 0)
	{
		len = prec;
	}
	for (i = 0; i < width - len; i++)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, ' ');
	}

	for (i = 0; str[i] != '\0' && i < len; i++)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, str[i]);
	}
	return (printed_characters);
}

/**
* cus_string_format - Prints the _printf function's argument
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int cus_string_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	char *str = va_arg(ptr, void *);
	int printed_characters = 0;
	int i = 0;
	char *hex = "0123456789ABCDEF";

	(void) (flag);
	(void) (width);
	(void) (prec);

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
			hex_format(hex, (unsigned int) str[i], buffer, buffer_index, "", 0, 0);
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
* rot13_string_format - Prints the _printf function's string argument
* encoded into rot13.
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/

int rot13_string_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	char *str = va_arg(ptr, char *);
	int i = 0;
	int printed_characters = 0;
	char c;

	(void) (flag);
	(void) (width);
	(void) (prec);

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
* rev_string_format - Prints the _printf function's string argument
* in reveresed
*
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int rev_string_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	char *str = va_arg(ptr, char *);
	int printed_characters = 0;
	char c;
	int str_len;

	(void) (flag);
	(void) (width);
	(void) (prec);

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

