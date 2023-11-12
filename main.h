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
	int (*func)(va_list ptr);
} spec_format;

int _printf(const char *format, ...);

int print_char_format(va_list ptr);
int print_string_format(va_list ptr);
int print_int_format(va_list ptr);
int print_binary_format(va_list ptr);
int _len(char *c);

#endif
