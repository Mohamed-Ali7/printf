#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
* int_format - Prints the _printf function's argument in int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flag to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/
int int_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	int i = va_arg(ptr, int);
	int x = 0, is_neg = 0, r;
	int printed_characters = 0;
	char nums[10];

	if (i == 0)
	{
		printed_characters +=
				print_flag_if_exist(flag, buffer, buffer_index, width, 1, 0, prec);
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
		return (printed_characters);
	}
	if (i < 0)
	{
		is_neg = 1;
	}

	for (x = 0; i != 0; x++)
	{
		r = (i % 10);
		if (r < 0)
			r *= -1;
		nums[x] = r + '0';
		i = i / 10;
	}

	printed_characters +=
			print_flag_if_exist(flag, buffer, buffer_index, width, x, is_neg, prec);

	while (x >= 1)
		printed_characters += add_to_buffer(buffer, buffer_index, nums[--x]);
	return (printed_characters);
}

/**
* unsigned_int_format - Prints the _printf function's argument
* in unsigned int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @width: Is the width of the specifier
* @prec: Is the precision of the specifier
* Return: The number of printed characters
*/

int unsigned_int_format(va_list ptr, char *buffer, int *buffer_index,
		char *flag, int width, int prec)
{
	unsigned int i = va_arg(ptr, unsigned int);
	unsigned int tmp = i;
	unsigned int divider = 1;
	int printed_characters = 0, len = 0;
	char num;

	(void) (flag);

	if (i == 0)
	{
		printed_characters +=
				print_flag_if_exist("", buffer, buffer_index, width, 1, 0, prec);
		printed_characters += add_to_buffer(buffer, buffer_index, '0');
		return (printed_characters);
	}
	while (tmp > 0)
	{
		tmp /= 10;
		if (tmp > 0)
		{
			divider *= 10;
		}
		len++;
	}
	printed_characters +=
				print_flag_if_exist("", buffer, buffer_index, width, len, 0, prec);

	while (divider >= 1)
	{
		num = ((i / divider) % 10) + '0';
		printed_characters += add_to_buffer(buffer, buffer_index, num);
		divider /= 10;
	}

	return (printed_characters);
}

