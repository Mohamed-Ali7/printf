#include "main.h"
#include <stdio.h>

/**
* print_add_format - Prints the _printf function's argument in address format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_add_format(va_list ptr, char *buffer, int *buffer_index)
{
	void *address = va_arg(ptr, void *);
	unsigned long add_val = (unsigned long) address;
	int index;
	unsigned long tmp = add_val;
	unsigned long divider = 1;
	int printed_characters = 0;
	char *hex = "0123456789abcdef";
	char *non = "(nil)";

	if (address == NULL)
	{
		for (index = 0; non[index] != '\0'; index++)
		{
			printed_characters += add_to_buffer(buffer, buffer_index, non[index]);
		}
		return (printed_characters);
	}
	printed_characters += add_to_buffer(buffer, buffer_index, '0');
	printed_characters += add_to_buffer(buffer, buffer_index, 'x');

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
		index = (add_val / divider) % 16;
		printed_characters = add_to_buffer(buffer, buffer_index, hex[index]);
		divider /= 16;
	}
	return (printed_characters);
}
