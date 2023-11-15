#include <unistd.h>
#include <stdarg.h>
#include "main.h"


/**
* lower_hex_format - Prints the _printf function's argument
* in lower hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int lower_hex_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	unsigned int i = va_arg(ptr, unsigned int);
	char *hex = "0123456789abcdef";

	return (hex_format(hex, i, buf, buf_ind, flag, w));
}

/**
* upper_hex_format - Prints the _printf function's argument
* in upper hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int upper_hex_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	unsigned int i = va_arg(ptr, unsigned int);
	char *hex = "0123456789ABCDEF";

	return (hex_format(hex, i, buf, buf_ind, flag, w));
}

/**
* hex_format - Prints the _printf function's argument
* in hexadecimal format
* @hx: Is the hex format in upper or lower letters
* @i: Is the number to print its hexadecimal format
* @bf: Is the buffer to store the printable character
* @bf_n: Is the current index of the buffer
* @f: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/

int hex_format(char *hx, unsigned int i, char *bf, int *bf_n, char *f, int w)
{
	unsigned int tmp = i;
	unsigned int divider = 1;
	int printed_characters = 0, index, len = 0, remind;

	if (i == 0)
		len = 1;
	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
			divider *= 16;
		len++;
	}
	remind = w - len;
	for (index = 0; index < remind; index++)
	{
		printed_characters += add_to_buffer(bf, bf_n, ' ');
	}
	for (index = 0; f[index] != '\0'; index++)
	{
		if (f[index] == '#')
		{
			for (index = 0; remind > 0 && index < 2; index++, remind--)
				*bf_n = *bf_n - 1;
			printed_characters += add_to_buffer(bf, bf_n, '0');
			if (hx[10] == 'A')
				printed_characters += add_to_buffer(bf, bf_n, 'X');
			else
				printed_characters += add_to_buffer(bf, bf_n, 'x');
			break;
		}
	}
	while (divider >= 1)
	{
		index = (i / divider) % 16;
		printed_characters += add_to_buffer(bf, bf_n, hx[index]);
		divider /= 16;
	}
	return (printed_characters);
}

