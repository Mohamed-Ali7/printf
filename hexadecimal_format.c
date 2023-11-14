#include <unistd.h>
#include <stdarg.h>
#include "main.h"


/**
* print_lower_hex_format - Prints the _printf function's argument
* in lower hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_lower_hex_format(va_list ptr, char *buffer, int *buffer_index)
{
	long i = va_arg(ptr, long);
	char *hex_format = "0123456789abcdef";

	return (print_hex_format(hex_format, i, buffer, buffer_index));
}

/**
* print_upper_hex_format - Prints the _printf function's argument
* in upper hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_upper_hex_format(va_list ptr, char *buffer, int *buffer_index)
{
	long int i = va_arg(ptr, long);
	char *hex_format = "0123456789ABCDEF";

	return (print_hex_format(hex_format, i, buffer, buffer_index));
}

/**
* print_hex_format - Prints the _printf function's argument
* in hexadecimal format
* @hex: Is the hex format in upper or lower letters
* @i: Is the number to print its hexadecimal format
* @buff: Is the buffer to store the printable character
* @buffer_ind: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_hex_format(char *hex, long i, char *buff, int *buffer_ind)
{
	long tmp = i;
	long divider = 1;
	int printed_characters = 0;
	int index;

	if (i == 0)
	{
		printed_characters = add_to_buffer(buff, buffer_ind, "0", 1);
		return (printed_characters);
	}

	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
		{
			divider *= 16;
		}
	}

	while (divider >= 1)
	{
		index = (i / divider) % 16;
		printed_characters = add_to_buffer(buff, buffer_ind, &hex[index], 1);
		divider /= 16;
	}
	return (printed_characters);
}
