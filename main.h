#ifndef PRINT_F_H
#define PRINT_F_H

#include <stdarg.h>

/**
* struct specifier_format - Is a struct that contains format specifiers
* and format functions
* @specifier: Is the specifier character
* @func: Is the pointer to a format function
* Description: Is used to point to invoke format function
* based on a specifier character
*/
typedef struct specifier_format
{
	char *specifier;
	int (*func)(va_list ptr, char *buffer, int *buffer_index, char *flags);
} spec_format;

int _printf(const char *format, ...);

int print_char_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_string_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_int_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_binary_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_unsigned_int_format(va_list p, char *buf, int *buf_in, char *flags);
int print_octal_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_lower_hex_format(va_list pt, char *buf, int *buf_ind, char *flags);
int print_upper_hex_format(va_list pt, char *buf, int *buf_ind, char *flags);
int add_to_buffer(char *buffer, int *buffer_index, char src);
int free_buffer(char *buf, int *buf_index);
int print_hex_format(char *h, unsigned int i, char *bf, int *bf_n, char *flg);
int print_cus_string_format(va_list pt, char *buf, int *buf_ind, char *flags);
int print_add_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_rot13_string_format(va_list pt, char *buf, int *buf_in, char *flags);
int print_rev_string_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_flag_if_exist(char *flag, char *buf, int *buf_index);
int print_unsigned_long_int(va_list p, char *buf, int *buf_in, char *flags);
int print_long_int_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_upper_long_hex(va_list ptr, char *buf, int *buf_ind, char *flag);
int print_lower_long_hex(va_list ptr, char *buf, int *buf_ind, char *flag);
int print_long_hex(char *hx, long i, char *bf, int *bf_n, char *flg);
int print_long_octal(va_list ptr, char *buf, int *buf_ind, char *flag);
int print_short_octal(va_list ptr, char *buf, int *buf_ind, char *flag);
int print_unsigned_short_int(va_list p, char *buf, int *buf_in, char *flags);
int print_short_int_format(va_list ptr, char *buf, int *buf_ind, char *flags);
int print_upper_short_hex(va_list ptr, char *buf, int *buf_ind, char *flag);
int print_lower_short_hex(va_list ptr, char *buf, int *buf_ind, char *flag);
int _len(char *c);

#endif