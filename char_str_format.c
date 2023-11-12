#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

int _len(char *c);

/**
* print_char_format - Prints the _printf function's argument in char format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/

int print_char_format(va_list ptr)
{
	char c = va_arg(ptr, int);

	write(1, &c, 1);
	return (1);
}

/**
* print_string_format - Prints the _printf function's argument in string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* Return: The number of printed characters
*/
int print_string_format(va_list ptr)
{
	char *str = va_arg(ptr, void *);
	int length;

	if (str == NULL)
	{
		str = "(null)";
	}
	length = _len(str);
	write(1, str, length);
	return (length);
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
