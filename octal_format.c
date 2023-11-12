#include <unistd.h>
#include <stdarg.h>

/**
* print_octal_format - Prints the _printf function's argument in octal
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/

int print_octal_format(va_list ptr)
{
	unsigned int i = va_arg(ptr, unsigned int);
	unsigned int tmp = i;
	int divider = 1;
	int length = 0;
	char num;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (tmp > 0)
	{
		tmp /= 8;
		if (tmp > 0)
		{
			divider *= 8;
		}
		length++;
	}

	while (divider >= 1)
	{
		num = ((i / divider) % 8) + '0';
		write(1, &num, 1);
		divider /= 8;
	}
	return (length);
}
