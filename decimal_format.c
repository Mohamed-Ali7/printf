#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
* print_int_format - Prints the _printf function's argument in int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_int_format(va_list ptr, char *buffer, int *buffer_index)
{
	int i = va_arg(ptr, int);
	int x = 0;
	unsigned int tmp = i;
	int printed_characters = 0;
	char nums[10];

	if (i == 0)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, "0", 1);
		return (printed_characters);
	}
	if (i < 0)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, "-", 1);
		tmp *= -1;
	}
	while (tmp != 0)
	{
		nums[x] = (tmp % 10) + '0';
		tmp = tmp / 10;
		x++;
	}
	while (x >= 1)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, &nums[x - 1], 1);
		x--;
	}

	return (printed_characters);
}

/**
* print_unsigned_int_format - Prints the _printf function's argument
* in unsigned int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_unsigned_int_format(va_list ptr, char *buffer, int *buffer_index)
{
	unsigned int i = va_arg(ptr, unsigned int);
	unsigned int tmp = i;
	int divider = 1;
	int printed_characters = 0;
	char nums[10];
	int length = 0;

	if (i == 0)
	{
		printed_characters += add_to_buffer(buffer, buffer_index, "0", 1);
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
		nums[length] = ((i / divider) % 10) + '0';
		length++;
		divider /= 10;
	}

	printed_characters += add_to_buffer(buffer, buffer_index, nums, length);
	return (printed_characters);
}
