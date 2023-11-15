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
 * @buf: Is the buffer to store the printable character
 * @buf_index: Is the current index of the buffer
 * Return: The number of printed characters
 */

int print_flag_if_exist(char *f, char *bf, int *bf_n, int w, int l, int is_ng)
{
	int printed_characters = 0;
	int i;
	int remind = w - l;

	if(is_ng)
		remind--;

	for (i = 0; i < remind; i++)
	{
		printed_characters += add_to_buffer(bf, bf_n, ' ');
	}
	for (i = 0; f[i] != '\0'; i++)
	{
		if (f[i] == '+')
		{
			if (!is_ng)
			{
				if (remind > 0)
					*bf_n = *bf_n - 1;
				printed_characters += add_to_buffer(bf, bf_n, '+');
			}
			f = NULL;
			break;
		}
	}
	if (f != NULL)
	{
		for (i = 0; f[i] != '\0'; i++)
		{
			if (f[i] == ' ')
			{
				if (remind > 0)
					*bf_n = *bf_n - 1;
				printed_characters += add_to_buffer(bf, bf_n, ' ');
				break;
			}
		}
	}
		
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

