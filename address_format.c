#include "main.h"
#include <stdio.h>

/**
* add_format - Prints the _printf function's argument in address format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* Return: The number of printed characters
*/

int add_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	void *address = va_arg(ptr, void *);
	unsigned long add_val = (unsigned long) address;
	int index, printed_characters = 0, len = 0;
	unsigned long tmp = add_val, divider = 1;
	char *hex = "0123456789abcdef", *non = "(nil)";

	if (address == NULL)
	{
		for (index = 0; non[index] != '\0'; index++)
			printed_characters += add_to_buffer(buf, buf_ind, non[index]);
		return (printed_characters);
	}

	
	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
			divider *= 16;
		len++;
	}

	printed_characters += print_flag_if_exist(flag, buf, buf_ind, w, len + 2, 0);

	printed_characters += add_to_buffer(buf, buf_ind, '0');
	printed_characters += add_to_buffer(buf, buf_ind, 'x');

	while (divider >= 1)
	{
		index = (add_val / divider) % 16;
		printed_characters += add_to_buffer(buf, buf_ind, hex[index]);
		divider /= 16;
	}
	return (printed_characters);
}

