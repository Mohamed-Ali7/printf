#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* char_format - Prints the _printf function's argument in char format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int char_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	char c = va_arg(ptr, int);
	int printed_characters = 0;
	(void) (flag);

	for (i = 0; i < w - 1; i++)
	{
		printed_characters += add_to_buffer(buf, buf_ind, ' ');
	}

	printed_characters += add_to_buffer(buf, buf_ind, c);

	return (printed_characters);
}

/**
* string_format - Prints the _printf function's argument in string format
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @fl: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int string_format(va_list ptr, char *buf, int *buf_ind, char *fl, int w)
{
	char *str = va_arg(ptr, char *);
	int i, len;
	int printed_characters = 0;
	(void) (fl);

	if (str == NULL)
	{
		str = "(null)";
	}

	len = _len(str);

	for (i = 0; i < w - len; i++)
	{
		printed_characters += add_to_buffer(buf, buf_ind, ' ');
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		printed_characters += add_to_buffer(buf, buf_ind, str[i]);
	}
	return (printed_characters);
}

/**
* cus_string_format - Prints the _printf function's argument
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int cus_string_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	char *str = va_arg(ptr, void *);
	int printed_characters = 0;
	int i = 0;
	char *hex = "0123456789ABCDEF";
	(void) (flag);
	(void) (w);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			printed_characters += add_to_buffer(buf, buf_ind, '\\');
			printed_characters += add_to_buffer(buf, buf_ind, 'x');
			if (str[i] <= 16)
			{
				printed_characters += add_to_buffer(buf, buf_ind, '0');
			}
			hex_format(hex, (unsigned int) str[i], buf, buf_ind, "", 0);
			i++;
		}
		else
		{
			printed_characters += add_to_buffer(buf, buf_ind, str[i]);
			i++;
		}
	}

	return (printed_characters);
}

/**
* rot13_string_format - Prints the _printf function's string argument
* encoded into rot13.
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flg: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/

int rot13_string_format(va_list ptr, char *buf, int *buf_ind, char *flg, int w)
{
	char *str = va_arg(ptr, char *);
	int i = 0;
	int printed_characters = 0;
	char c;
	(void) (flg);
	(void) (w);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[i] != '\0')
	{
		c = str[i];
		if ((c >= 'A' && c <= 'Z'))
		{
			if ((c + 13) > 'Z')
			{
				c -= 26;
			}
			c += 13;
		}
		else if ((c >= 'a' && c <= 'z'))
		{
			if ((c + 13) > 'z')
			{
				c -= 26;
			}
			c += 13;
		}
		printed_characters += add_to_buffer(buf, buf_ind, c);
		i++;
	}
	return (printed_characters);
}

/**
* rev_string_format - Prints the _printf function's string argument
* in reveresed
*
* @ptr: Is the pointer to the list of arguments of the _printf function
* @buf: Is the buffer to store the printable character
* @buf_ind: Is the current index of the buffer
* @flag: Are the flags to check for custom print
* @w: Is the width of the specifier
* Return: The number of printed characters
*/
int rev_string_format(va_list ptr, char *buf, int *buf_ind, char *flag, int w)
{
	char *str = va_arg(ptr, char *);
	int printed_characters = 0;
	char c;
	int str_len;
	(void) (flag);
	(void) (w);

	if (str == NULL)
	{
		str = "(null)";
	}
	str_len = _len(str);

	while (str_len >= 1)
	{
		c = str[str_len - 1];

		printed_characters += add_to_buffer(buf, buf_ind, c);
		str_len--;
	}
	return (printed_characters);
}

