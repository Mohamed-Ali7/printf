#include <unistd.h>
#include <stdarg.h>
#include "main.h"


/**
* print_lower_hex_format - Prints the _printf function's argument
* in lower hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* Return: The number of printed characters
*/
int print_lower_hex_format(va_list ptr, char *buf, int *buf_ind, char *flag)
{
	unsigned int i = va_arg(ptr, unsigned int);
	char *hex_format = "0123456789abcdef";

	return (print_hex_format(hex_format, i, buf, buf_ind, flag));
}

/**
* print_upper_hex_format - Prints the _printf function's argument
* in upper hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* Return: The number of printed characters
*/
int print_upper_hex_format(va_list ptr, char *buf, int *buf_ind, char *flag)
{
	unsigned int i = va_arg(ptr, unsigned int);
	char *hex_format = "0123456789ABCDEF";

	return (print_hex_format(hex_format, i, buf, buf_ind, flag));
}

/**
* print_hex_format - Prints the _printf function's argument
* in hexadecimal format
* @hx: Is the hex format in upper or lower letters
* @i: Is the number to print its hexadecimal format
* @bf: Is the buffer to store the printable character
* @bf_n: Is the current index of the buffer
* @flg: Are the flags to check for custom print
* Return: The number of printed characters
*/

int print_hex_format(char *hx, unsigned int i, char *bf, int *bf_n, char *flg)
{
	unsigned int tmp = i;
	unsigned int divider = 1;
	int printed_characters = 0;
	int index;

	if (i == 0)
	{
		printed_characters = add_to_buffer(bf, bf_n, '0');
		return (printed_characters);
	}

	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
		{
			divider *= 16;
		}
	}
	for (index = 0; flg[index] != '\0'; index++)
	{
		if (flg[index] == '#')
		{
			printed_characters = add_to_buffer(bf, bf_n, '0');
			if (hx[10] == 'A')
				printed_characters = add_to_buffer(bf, bf_n, 'X');
			else
				printed_characters = add_to_buffer(bf, bf_n, 'x');
			break;
		}
	}

	while (divider >= 1)
	{
		index = (i / divider) % 16;
		printed_characters = add_to_buffer(bf, bf_n, hx[index]);
		divider /= 16;
	}
	return (printed_characters);
}

