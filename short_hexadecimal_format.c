#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int short_hex(char *hwx, unsigned short i, char *buffer, int *buffer_index,
		char *flag, int width, int prec);

/**
* lower_short_hex - Prints the _printf function's argument
* in lower short hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int lower_short_hex(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned short i = va_arg(ptr, int);
	char *hex_format = "0123456789abcdef";

	return (short_hex(hex_format, i, buffer, buffer_index, flag, width, prec));
}

/**
* upper_short_hex - Prints the _printf function's argument
* in upper short hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int upper_short_hex(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned short i = va_arg(ptr, int);
	char *hex_format = "0123456789ABCDEF";

	return (short_hex(hex_format, i, buffer, buffer_index, flag, width, prec));
}

/**
* short_hex - Prints the _printf function's argument
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

int short_hex(char *hex, unsigned short i, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned short tmp = i;
	unsigned short divider = 1;
	int printed_characters = 0;
	int index, len = 0, remind;

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
	{
		printed_characters += add_to_buffer(buffer, buffer_index, ' ');
	}
	
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

