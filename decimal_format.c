#include <unistd.h>
#include <stdarg.h>

/**
* print_int_format - Prints the _printf function's argument in int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/
int print_int_format(va_list ptr)
{
	int i = va_arg(ptr, int);
	int x = 0;
	unsigned int tmp = i;
	int length = 0;
	char nums[10];

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
		length++;
	}
	while (tmp != 0)
	{
		nums[x] = (tmp % 10) + '0';
		tmp = tmp / 10;
		x++;
		length++;
	}
	while (x >= 1)
	{
		write(1, &nums[x - 1], 1);
		x--;
	}
	return (length);
}

/**
* print_unsigned_int_format - Prints the _printf function's argument
* in unsigned int format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/

int print_unsigned_int_format(va_list ptr)
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
		tmp /= 10;
		if (tmp > 0)
		{
			divider *= 10;
		}
		length++;
	}

	while (divider >= 1)
	{
		num = ((i / divider) % 10) + '0';
		write(1, &num, 1);
		divider /= 10;
	}
	return (length);
}
