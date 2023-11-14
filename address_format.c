#include "main.h"
#include <stdio.h>
#include <stdint.h>
/**
* print_add_format - Prints the _printf function's argument in address format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_add_format(va_list ptr, char *buffer, int *buffer_index)
{
	void *address = va_arg(ptr, void *);
	unsigned long add_val = (uintptr_t) address;
	int printed_characters = 0;
	char *hex = "0123456789abcdef";

	printed_characters += add_to_buffer(buffer, buffer_index, "0x", 2);
	printed_characters += print_hex_format(hex, add_val, buffer, buffer_index);

	return (printed_characters);
}
