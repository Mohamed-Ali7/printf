#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* print_binary_format - Prints the _printf function's argument in binary foramt
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_binary_format(va_list ptr, char *buffer, int *buffer_index)
{
	unsigned int val = va_arg(ptr, unsigned int);
	int printed_characters = 0;
	unsigned int tmp = val;
	unsigned int divider = 1;
	char bit;

	if (val == 0)
	{
		printed_characters = add_to_buffer(buffer, buffer_index, "0", 1);
		return (printed_characters);
	}

	while (val > 0)
	{
		val /= 2;
		if (val != 0)
		{
			divider *= 2;
		}
	}

	while (divider >= 1)
	{
		bit = ((tmp / divider) % 2) + '0';
		printed_characters = add_to_buffer(buffer, buffer_index, &bit, 1);
		divider /= 2;
	}

	return (printed_characters);
}
