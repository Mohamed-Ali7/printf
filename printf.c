#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


int check_flag(const char *str);
int width(const char *str, va_list ptr, int *format_index);

/**
* get_specifier_format - Creates and Initialize an array of spec_format sruct
* Return: The created array
*/

spec_format *get_specifier_format()
{
	spec_format *spec = malloc(sizeof(spec_format) * 26);

	if (spec == NULL)
		exit(1);

	spec[0].specifier = "c", spec[0].func = char_format;
	spec[1].specifier = "s", spec[1].func = string_format;
	spec[2].specifier = "d", spec[2].func = int_format;
	spec[3].specifier = "i", spec[3].func = int_format;
	spec[4].specifier = "b", spec[4].func = binary_format;
	spec[5].specifier = "u", spec[5].func = unsigned_int_format;
	spec[6].specifier = "o", spec[6].func = octal_format;
	spec[7].specifier = "x", spec[7].func = lower_hex_format;
	spec[8].specifier = "X", spec[8].func = upper_hex_format;
	spec[9].specifier = "S", spec[9].func = cus_string_format;
	spec[10].specifier = "p", spec[10].func = add_format;
	spec[11].specifier = "R", spec[11].func = rot13_string_format;
	spec[12].specifier = "r", spec[12].func = rev_string_format;
	spec[13].specifier = "lu", spec[13].func = unsigned_long_int;
	spec[14].specifier = "ld", spec[14].func = long_int_format;
	spec[15].specifier = "li", spec[15].func = long_int_format;
	spec[16].specifier = "lX", spec[16].func = upper_long_hex;
	spec[17].specifier = "lx", spec[17].func = lower_long_hex;
	spec[18].specifier = "lo", spec[18].func = long_octal;
	spec[19].specifier = "ho", spec[19].func = short_octal;
	spec[20].specifier = "hd", spec[20].func = short_int_format;
	spec[21].specifier = "hi", spec[21].func = short_int_format;
	spec[22].specifier = "hu", spec[22].func = unsigned_short_int;
	spec[23].specifier = "hx", spec[23].func = lower_short_hex;
	spec[24].specifier = "hX", spec[24].func = upper_short_hex;
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
	int j, i, buf_ind = 0, printed_chars = 0, flag_count, wid;
	spec_format *spec = get_specifier_format();
	char buffer[1024], flag[50];
	va_list listPtr;

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
				flag[j] = format[i];
			}
			flag[j] = '\0';
			wid = width(format, listPtr, &i);
			for (j = 0; spec[j].specifier != NULL; j++)
			{
				if (spec[j].specifier[0] == format[i])
				{
					if (spec[j].specifier[1] != '\0')
					{
					if (spec[j].specifier[1] == format[i + 1])
						{
						printed_chars += spec[j].func(listPtr, buffer, &buf_ind, flag, wid);
						i++;
						break;
						}
					continue;
					}
					else
						printed_chars += spec[j].func(listPtr, buffer, &buf_ind, flag, wid);
					break;
				}
				if (spec[j + 1].specifier == NULL)
				{
					printed_chars += add_to_buffer(buffer, &buf_ind, format[i - 1]);
					printed_chars += add_to_buffer(buffer, &buf_ind, format[i]);
				}
			}
			continue;
		}
		printed_chars += add_to_buffer(buffer, &buf_ind, format[i]);
	}
	printed_chars += free_buffer(buffer, &buf_ind);
	va_end(listPtr), free(spec);
	return (printed_chars);
}

/**
 * width - fetch the width of the specifier of the format string
 * @str: Is the format string
 * @ptr: Is the pointer to _printf funtion arguments
 * @index: Is the current index of the format string (str)
 * Return: The width of the variable
 */
int width(const char *str, va_list ptr, int *index)
{
	int wid = 0;

	if (str[*index] == '*')
	{
		wid = va_arg(ptr, int);
		*index = *index + 1;
		return (wid);
	}
	while (str[*index] != '\0' && (str[*index] >= '0' && str[*index] <= '9'))
	{
		wid *= 10;
		wid += (str[*index] - '0');
		*index = *index + 1;
	}

	return (wid);
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

