#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _len(char *c);

/**
* print_char_format - Prints the _printf function's argument in char format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/

int print_char_format(va_list ptr, char *buffer, int *buffer_index)
{
	char c = va_arg(ptr, int);
	int printed_characters = 0;

	printed_characters += add_to_buffer(buffer, buffer_index, &c, 1);

	return (printed_characters);
}

/**
* print_string_format - Prints the _printf function's argument in string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buffer: Is the buffer to store the printable character
* @buffer_index: Is the current index of the buffer
* Return: The number of printed characters
*/
int print_string_format(va_list ptr, char *buffer, int *buffer_index)
{
	char *str = va_arg(ptr, void *);
	int length;
	int printed_characters = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	length = _len(str);

	printed_characters += add_to_buffer(buffer, buffer_index, str, length);

	return (printed_characters);
}

/**
* _len - Calculates the length of a string
* @s: Is the string to calcualte its length
* Return: The length of the string (s)
*/

int _len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
