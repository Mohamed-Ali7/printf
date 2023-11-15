#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
* octal_format - Prints the _printf function's argument in octal
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/

int octal_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	unsigned int i = va_arg(ptr, unsigned int);
	unsigned int tmp = i;
	unsigned int divider = 1;
	int printed_characters = 0;
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
	remind = w - len;
	for (x = 0; x < remind; x++)
	{
		printed_characters += add_to_buffer(buf, buf_ind, ' ');
	}
	for (x = 0; flag[x] != '\0'; x++)
	{
		if (flag[x] == '#' && i != 0)
		{
			if (remind > 0)
				*buf_ind = *buf_ind - 1;
			printed_characters += add_to_buffer(buf, buf_ind, '0');
			break;
		}
	}
	while (divider >= 1)
	{
		num = ((i / divider) % 8) + '0';
		printed_characters += add_to_buffer(buf, buf_ind, num);
		divider /= 8;
	}
	return (printed_characters);
}

