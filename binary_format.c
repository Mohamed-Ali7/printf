#include <stdarg.h>
#include <unistd.h>

/**
* print_binary_format - Prints the _printf function's argument in binary foramt
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/

int print_binary_format(va_list ptr)
{
	unsigned int val = va_arg(ptr, unsigned int);
	int length = 0;
	unsigned int tmp = val;
	unsigned int divider = 1;
	char bit;

	if (val == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (val > 0)
	{
		val /= 2;
		if (val != 0)
		{
			divider *= 2;
		}
	}

	while (divider >= 1)
	{
		bit = ((tmp / divider) % 2) + '0';
		write(1, &bit, 1);
		divider /= 2;
		length++;
	}

	return (length);
}
