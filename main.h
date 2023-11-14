#ifndef PRINT_F_H
#define PRINT_F_H
#include <stdarg.h>

/**
* struct specifier_format - Is a struct that contains format specifiers
* and format functions
* @specifier: Is the specifier character
* @func: Is the pointer to a format function
*/
typedef struct specifier_format
{
	char *specifier;
	int (*func)(va_list ptr, char *buffer, int *buffer_index);
} spec_format;

int _printf(const char *format, ...);

int print_char_format(va_list ptr, char *buffer, int *buffer_index);
int print_string_format(va_list ptr, char *buffer, int *buffer_index);
int print_int_format(va_list ptr, char *buffer, int *buffer_index);
int print_binary_format(va_list ptr, char *buffer, int *buffer_index);
int print_unsigned_int_format(va_list ptr, char *buffer, int *buffer_index);
int print_octal_format(va_list ptr, char *buffer, int *buffer_index);
int print_lower_hex_format(va_list ptr, char *buffer, int *buffer_index);
int print_upper_hex_format(va_list ptr, char *buffer, int *buffer_index);
int add_to_buffer(char *buffer, int *buffer_index, char *src, int size);
int free_buffer(char *buf, int *buf_index);
int print_hex_format(char *hex, unsigned int i, char *buffer, int *buffer_index);
int print_cus_string_format(va_list ptr, char *buffer, int *buffer_index);
int print_add_format(va_list ptr, char *buffer, int *buffer_index);
int _len(char *c);

#endif
