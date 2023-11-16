#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
* unsigned_long_int - Prints the _printf function's argument
* in unsigned long int format
* @p: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/

int unsigned_long_int(va_list p, char *buf, int *buf_ind, char *flag, int w)
{
	unsigned long i = va_arg(p, unsigned long);
	unsigned long tmp = i;
	unsigned long divider = 1;
	int printed_characters = 0, len = 0, x, remind;
	char num;
	(void) (flag);

	if (i == 0)
	{
		for (x = 0; x < w - 1; x++)
		{
			printed_characters += add_to_buffer(buf, buf_ind, ' ');
		}
		printed_characters += add_to_buffer(buf, buf_ind, '0');
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
	remind = w - len;
	for (x = 0; x < remind; x++)
	{
		printed_characters += add_to_buffer(buf, buf_ind, ' ');
	}

	while (divider >= 1)
	{
		num = ((i / divider) % 10) + '0';
		printed_characters += add_to_buffer(buf, buf_ind, num);
		divider /= 10;
	}

	return (printed_characters);
}

/**
* long_int_format - Prints the _printf function's argument
* in long int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flags: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int long_int_format(va_list ptr, char *buf, int *buf_ind, char *flags, int w)
{
	long i = va_arg(ptr, long);
	int x = 0, r;
	int printed_characters = 0, is_neg = 0;
	char nums[32];

	if (i == 0)
	{
		printed_characters += print_flag_if_exist(flags, buf, buf_ind, w, 1, 0);
		printed_characters += add_to_buffer(buf, buf_ind, '0');
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

	printed_characters += print_flag_if_exist(flags, buf, buf_ind, w, x, is_neg);
	if (is_neg)
	{
		printed_characters += add_to_buffer(buf, buf_ind, '-');
	}
	while (x >= 1)
		printed_characters += add_to_buffer(buf, buf_ind, nums[--x]);
	return (printed_characters);
}

