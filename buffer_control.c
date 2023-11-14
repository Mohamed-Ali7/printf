#include<unistd.h>
#include "main.h"
#include <stdlib.h>

/**
 * add_to_buffer - Add character to the buffer to be printed
 * @buffer: Is the buffer in usage
 * @buffer_index: Is the current index of the buffer
 * @src: are the characters that will be saved in the buffer
 * @size: Is the counti of the characters (src)
 * Return: The number of printed characters
 */
int add_to_buffer(char *buffer, int *buffer_index, char *src, int size)
{
	int i;
	int printed_characters = 0;

	for (i = 0; i < size; i++)
	{
		buffer[*buffer_index] = src[i];
		*buffer_index = *buffer_index + 1;

		if (*buffer_index == BUFF_SIZE)
		{
			printed_characters += free_buffer(buffer, buffer_index);

		}
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
