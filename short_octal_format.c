#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
* short_octal - Prints the _printf function's argument in short octal
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/

int short_octal(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned short i = va_arg(ptr, int);
	unsigned short tmp = i;
	unsigned short divider = 1, printed_characters = 0;
	char num;
	int x, len = 0, remind;

	while (tmp > 0)
	{
		tmp /= 8;
		if (tmp > 0)
			divider *= 8;
		len++;
	}
	if (len == 0)
		len++;
	remind = width - len;
	prec -= len;
	if (prec > 0)
		remind = width - (prec + len);
	for (x = 0; x < remind; x++)
		printed_characters += add_to_buffer(buffer, buffer_index, ' ');
	if (prec <= 0)
	{
		for (x = 0; flag[x] != '\0'; x++)
		{
			if (flag[x] == '#' && i != 0)
			{
				if (remind > 0)
					*buffer_index = *buffer_index - 1;
				printed_characters += add_to_buffer(buffer, buffer_index, '0');
				break;
			}
		}
	}
	for (x = 0; x < prec; x++)
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
	while (divider >= 1)
	{
		num = ((i / divider) % 8) + '0';
		printed_characters += add_to_buffer(buffer, buffer_index, num);
		divider /= 8;
	}
	return (printed_characters);
}

