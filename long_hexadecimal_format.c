#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
* lower_long_hex - Prints the _printf function's argument
* in lower long hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int lower_long_hex(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned long i = va_arg(ptr, unsigned long);
	char *hex_format = "0123456789abcdef";

	return (long_hex(hex_format, i, buffer, buffer_index, flag, width, prec));
}

/**
* upper_long_hex - Prints the _printf function's argument
* in upper long hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int upper_long_hex(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned long i = va_arg(ptr, unsigned long);
	char *hex_format = "0123456789ABCDEF";

	return (long_hex(hex_format, i, buffer, buffer_index, flag, width, prec));
}

/**
* long_hex - Prints the _printf function's argument
* in hexadecimal format
* @hex: Is the hex format in upper or lower letters
* @i: Is the number to print its hexadecimal format
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/

int long_hex(char *hex, unsigned long i, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned long tmp = i, divider = 1;
	int printed_characters = 0, index, len = 0, remind;

	if (i == 0)
		len = 1;
	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
			divider *= 16;
		len++;
	}
	remind = width - len;
	prec -= len;
	if (prec > 0)
		remind = width - (prec + len);
	for (index = 0; index < remind; index++)
		printed_characters += add_to_buffer(buffer, buffer_index, ' ');
	for (index = 0; flag[index] != '\0'; index++)
	{
		if (flag[index] == '#' && i != 0)
		{
			for (index = 0; remind > 0 && index < 2; index++, remind--)
				*buffer_index = *buffer_index - 1;
			printed_characters += add_to_buffer(buffer, buffer_index, '0');
			if (hex[10] == 'A')
				printed_characters += add_to_buffer(buffer, buffer_index, 'X');
			else
				printed_characters += add_to_buffer(buffer, buffer_index, 'x');
			break;
		}
	}
	for (index = 0; index < prec; index++)
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
	while (divider >= 1)
	{
		index = (i / divider) % 16;
		printed_characters += add_to_buffer(buffer, buffer_index, hex[index]);
		divider /= 16;
	}
	return (printed_characters);
}

