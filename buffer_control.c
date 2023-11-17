#include<unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * add_to_buffer - Add character to the buffer to be printed
 * @buffer: Is the buffer in usage
 * @buffer_index: Is the current index of the buffer
 * @src: is the character that will be saved in the buffer
 * Return: The number of printed characters
 */
int add_to_buffer(char *buffer, int *buffer_index, char src)
{
	int printed_characters = 0;

	buffer[*buffer_index] = src;
	*buffer_index = *buffer_index + 1;

	if (*buffer_index == 1024)
	{
		printed_characters += free_buffer(buffer, buffer_index);

	}

	return (printed_characters);
}

/**
 * free_buffer - prints the buffer content to the standard output to reuse it
 * and reinitialize the buffer index with 0
 * @buf: Is the buffer to be printed
 * @buf_index: Is the current index of the buffer
 * which in this case is the buffer size
 * Return: The number of printed character
 */

int free_buffer(char *buf, int *buf_index)
{
	int index = *buf_index;

	write(1, buf, index);

	*buf_index = 0;
	return (index);
}


/**
 * print_flag_if_exist - Checks for flags to print
 * @flag: is the flag to check
 * @buffer: Is the buffer to store the printable character
 * @buffer_index: Is the current index of the buffer
 * @width: Is the width of the specifier
 * @length: Is the len of the variable which is being refered to by the specifier
 * @is_neg: To clear whether the number is negative or not
 * @prec: Is the precision of the specifier
 * Return: The number of printed characters
 */

int print_flag_if_exist(char *flag, char *buffer, int *buffer_index,
		int width, int length, int is_neg, int prec)
{
	int printed_characters = 0, i, remind = width - length;

	prec = prec - length;
	if (is_neg)
		remind--;

	if (prec > 0)
	{
		remind = width - (prec + length);
		if (is_neg)
			remind--;
	}

	for (i = 0; i < remind; i++)
		printed_characters += add_to_buffer(buffer, buffer_index, ' ');

	if (!is_neg)
	{
		for (i = 0; flag[i] != '\0'; i++)
		{
			if (flag[i] == '+')
			{
				if (remind > 0)
					*buffer_index = *buffer_index - 1;
				printed_characters += add_to_buffer(buffer, buffer_index, '+');
				flag = NULL;
				break;
			}
		}
	
		if (flag != NULL)
		{
			for (i = 0; flag[i] != '\0'; i++)
			{
				if (flag[i] == ' ')
				{
					if (remind > 0)
						*buffer_index = *buffer_index - 1;
					printed_characters += add_to_buffer(buffer, buffer_index, ' ');
					break;
				}
			}
		}
	}
	else
		printed_characters += add_to_buffer(buffer, buffer_index, '-');

	for (i = 0; i < prec; i++)
		printed_characters += add_to_buffer(buffer, buffer_index, '0');

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

