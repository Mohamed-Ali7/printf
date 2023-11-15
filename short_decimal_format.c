#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
* print_unsigned_short_int - Prints the _printf function's argument
* in unsigned short int format
* @p: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flags: Are the flags to check for custom print
* Return: The number of printed characters
*/

int print_unsigned_short_int(va_list p, char *buf, int *buf_ind, char *flags)
{
	unsigned short i = va_arg(p, int);
	unsigned short tmp = i;
	int divider = 1;
	int printed_characters = 0;
	char num;
	(void) (flags);

	if (i == 0)
	{
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
* print_short_int_format - Prints the _printf function's argument
* in long int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flags: Are the flags to check for custom print
* Return: The number of printed characters
*/
int print_short_int_format(va_list ptr, char *buf, int *buf_ind, char *flags)
{
	short i = va_arg(ptr, int);
	int x = 0;
	unsigned short tmp = i;
	int printed_characters = 0;
	char nums[32];

	if (i == 0)
	{
		printed_characters += add_to_buffer(buf, buf_ind, '0');
		printed_characters += print_flag_if_exist(flags, buf, buf_ind);
		return (printed_characters);
	}
	if (i < 0)
	{
		printed_characters += add_to_buffer(buf, buf_ind, '-');
		tmp *= -1;
	}
	else
	{
		printed_characters += print_flag_if_exist(flags, buf, buf_ind);
	}
	for (x = 0; tmp != 0; x++)
	{
		nums[x] = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	while (x >= 1)
		printed_characters += add_to_buffer(buf, buf_ind, nums[--x]);
	return (printed_characters);
}

