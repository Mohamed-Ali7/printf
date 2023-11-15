#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
int check_flag(const char *str);

/**
* get_specifier_format - Creates and Initialize an array of spec_format sruct
* Return: The created array
*/

spec_format *get_specifier_format()
{
	spec_format *spec = malloc(sizeof(spec_format) * 26);

	if (spec == NULL)
		exit(1);

	spec[0].specifier = "c", spec[0].func = print_char_format;
	spec[1].specifier = "s", spec[1].func = print_string_format;
	spec[2].specifier = "d", spec[2].func = print_int_format;
	spec[3].specifier = "i", spec[3].func = print_int_format;
	spec[4].specifier = "b", spec[4].func = print_binary_format;
	spec[5].specifier = "u", spec[5].func = print_unsigned_int_format;
	spec[6].specifier = "o", spec[6].func = print_octal_format;
	spec[7].specifier = "x", spec[7].func = print_lower_hex_format;
	spec[8].specifier = "X", spec[8].func = print_upper_hex_format;
	spec[9].specifier = "S", spec[9].func = print_cus_string_format;
	spec[10].specifier = "p", spec[10].func = print_add_format;
	spec[11].specifier = "R", spec[11].func = print_rot13_string_format;
	spec[12].specifier = "r", spec[12].func = print_rev_string_format;
	spec[13].specifier = "lu", spec[13].func = print_unsigned_long_int;
	spec[14].specifier = "ld", spec[14].func = print_long_int_format;
	spec[15].specifier = "li", spec[15].func = print_long_int_format;
	spec[16].specifier = "lX", spec[16].func = print_upper_long_hex;
	spec[17].specifier = "lx", spec[17].func = print_lower_long_hex;
	spec[18].specifier = "lo", spec[18].func = print_long_octal;
	spec[19].specifier = "ho", spec[19].func = print_short_octal;
	spec[20].specifier = "hd", spec[20].func = print_short_int_format;
	spec[21].specifier = "hi", spec[21].func = print_short_int_format;
	spec[22].specifier = "hu", spec[22].func = print_unsigned_short_int;
	spec[23].specifier = "hx", spec[23].func = print_lower_short_hex;
	spec[24].specifier = "hX", spec[24].func = print_upper_short_hex;
	spec[25].specifier = NULL;
	spec[25].func = NULL;
	return (spec);
}


/**
* _printf - Produces output according to a format.
* @format: Is string contains both text and format specifiers, which are
* placeholders for the values to print
* Return: The number of printed characters
*/

int _printf(const char *format, ...)
{
	int j, i, buffer_index = 0, printed_chars = 0, flag_count;
	spec_format *spec = get_specifier_format();
	char buffer[1024], flags[50];
	va_list listPtr;
	char ch;

	if (format == NULL)
		free(spec), exit(1);
	va_start(listPtr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			if (format[i] == '\0' || (format[i] == ' ' && format[i + 1] == '\0'))
				free(spec), exit(1);
			flag_count = check_flag(format + i);
			for (j = 0; j < flag_count; j++, i++)
			{
				flags[j] = format[i];
			}
			flags[j] = '\0';
			for (j = 0; spec[j].specifier != NULL; j++)
			{
				if (spec[j].specifier[0] == format[i])
				{
					ch = spec[j].specifier[1];
					if (ch != '\0' && ch == format[i + 1])
					{
						i++;
						printed_chars += spec[j].func(listPtr, buffer, &buffer_index, flags);
						break;
					}
					else if (ch != '\0' && ch != format[i + 1])
						continue;
					printed_chars += spec[j].func(listPtr, buffer, &buffer_index, flags);
					break;
				}
				if (spec[j + 1].specifier == NULL)
				{
					printed_chars += add_to_buffer(buffer, &buffer_index, format[i - 1]);
					printed_chars += add_to_buffer(buffer, &buffer_index, format[i]);
				}
			}
			continue;
		}
		printed_chars += add_to_buffer(buffer, &buffer_index, format[i]);
	}
	printed_chars += free_buffer(buffer, &buffer_index);
	va_end(listPtr), free(spec);
	return (printed_chars);
}

/**
 * check_flag - Checks for flags to cutom the printing format
 * @str: Is the string that will search for flags in
 * Return: The number of founded flags
 */

int check_flag(const char *str)
{
	int checker = 1;
	int flag_count = 0;
	int i = 0;

	while (checker > 0 && str[i] != '\0')
	{
		switch (str[i])
		{

			case '+':
				checker++;
				flag_count++;
				break;

			case ' ':
				checker++;
				flag_count++;
				break;

			case '#':
				checker++;
				flag_count++;
				break;
			default:
				checker = 0;

		}
		i++;
	}

	return (flag_count);
}