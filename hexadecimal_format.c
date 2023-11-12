#include <unistd.h>
#include <stdarg.h>

int print_hex_format(char *hex_counter, unsigned int i);

/**
* print_lower_hex_format - Prints the _printf function's argument
* in lower hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/
int print_lower_hex_format(va_list ptr)
{
	unsigned int i = va_arg(ptr, unsigned int);
	char *hex_format = "0123456789abcdef";

	return (print_hex_format(hex_format, i));
}

/**
* print_upper_hex_format - Prints the _printf function's argument
* in upper hexadecimal format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/
int print_upper_hex_format(va_list ptr)
{
	unsigned int i = va_arg(ptr, unsigned int);
	char *hex_format = "0123456789ABCDEF";

	return (print_hex_format(hex_format, i));
}

/**
* print_hex_format - Prints the _printf function's argument
* in hexadecimal format
* @hex_counter: Is the hex format in upper or lower letters
* @i: Is the number to print its hexadecimal format
* Return: The number of printed characters
*/

int print_hex_format(char *hex_counter, unsigned int i)
{
	unsigned int tmp = i;
	int divider = 1;
	int length = 0;
	int index;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (tmp > 0)
	{
		tmp /= 16;
		if (tmp > 0)
		{
			divider *= 16;
		}
		length++;
	}

	while (divider >= 1)
	{
		index = (i / divider) % 16;
		write(1, &hex_counter[index], 1);
		divider /= 16;
	}
	return (length);
}
