#include "main.h"
#include <stddef.h>

/**
* add_format - Prints the _printf function's argument in address format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int add_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	void *address = va_arg(ptr, void *);
	unsigned long add_val = (unsigned long) address;
	int index, printed_characters = 0, len = 0;
	unsigned long tmp = add_val, divider = 1;
	char *hex = "0123456789abcdef", *non = "(nil)";

	if (address == NULL)
	{
		for (index = 0; index < width - 5; index++)
			printed_characters += add_to_buffer(buffer, buffer_index, ' ');
		for (index = 0; non[index] != '\0'; index++)
			printed_characters += add_to_buffer(buffer, buffer_index, non[index]);
		return (printed_characters);
	}
	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
			divider *= 16;
		len++;
	}
	if (prec > 0)
	{
		len -= 2;
		width -= 2;
	}
	printed_characters +=
		print_flag_if_exist(flag, buffer, buffer_index, width, len + 2, 0, prec);
	if (prec > 0)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
		buffer[*buffer_index - (prec - len)] = '0';
		buffer[*buffer_index - (prec - len - 1)] = 'x';
	}
	else
	{
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
		printed_characters += add_to_buffer(buffer, buffer_index, 'x');
	}
	while (divider >= 1)
	{
		index = (add_val / divider) % 16;
		printed_characters += add_to_buffer(buffer, buffer_index, hex[index]);
		divider /= 16;
	}
	return (printed_characters);
}

