#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
* print_octal_format - Prints the _printf function's argument in octal
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_octal_format(va_list ptr, char *buffer, int *buffer_index)
{
	unsigned int i = va_arg(ptr, unsigned int);
	unsigned int tmp = i;
	int divider = 1;
	int printed_characters = 0;
	char num;

	if (i == 0)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, "0", 1);
		return (printed_characters);
	}

	while (tmp > 0)
	{
		tmp /= 8;
		if (tmp > 0)
		{
			divider *= 8;
		}
	}

	while (divider >= 1)
	{
		num = ((i / divider) % 8) + '0';
		printed_characters += add_to_buffer(buffer, buffer_index, &num, 1);
		divider /= 8;
	}

	return (printed_characters);
}
