#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* binary_format - Prints the _printf function's argument in binary foramt
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @fl: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/

int binary_format(va_list ptr, char *buf, int *buf_ind, char *fl, int w)
{
	unsigned int val = va_arg(ptr, unsigned int);
	int printed_characters = 0;
	unsigned int tmp = val;
	unsigned int divider = 1;
	char bit;

	(void) (fl);
	(void) (w);

	if (val == 0)
	{
		printed_characters += add_to_buffer(buf, buf_ind, '0');
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
		printed_characters += add_to_buffer(buf, buf_ind, bit);
		divider /= 2;
	}

	return (printed_characters);
}

