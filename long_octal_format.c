#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
* print_long_octal - Prints the _printf function's argument in long octal
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* Return: The number of printed characters
*/

int print_long_octal(va_list ptr, char *buf, int *buf_ind, char *flag)
{
	long i = va_arg(ptr, long);
	long tmp = i;
	long divider = 1;
	int printed_characters = 0;
	char num;
	int x;

	if (i == 0)
	{
		printed_characters += add_to_buffer(buf, buf_ind, '0');
		return (printed_characters);
	}

	for (x = 0; flag[x] != '\0'; x++)
	{
		if (flag[x] == '#')
		{
			printed_characters += add_to_buffer(buf, buf_ind, '0');
			break;
		}
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
		printed_characters += add_to_buffer(buf, buf_ind, num);
		divider /= 8;
	}

	return (printed_characters);
}