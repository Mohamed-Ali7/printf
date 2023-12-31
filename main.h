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
	int (*func)(va_list ptr, char *buf, int *buf_ind, char *flg, int w, int prc);
} spec_format;

int _printf(const char *format, ...);

int char_format(va_list, char *, int *, char *, int, int);
int string_format(va_list, char *, int *, char *, int, int);
int int_format(va_list, char *, int *, char *, int, int);
int binary_format(va_list, char *, int *, char *, int, int);
int unsigned_int_format(va_list, char *, int *, char *, int, int);
int octal_format(va_list, char *, int *, char *, int, int);
int lower_hex_format(va_list, char *, int *, char *, int, int);
int upper_hex_format(va_list, char *, int *, char *, int, int);
int add_to_buffer(char *, int *, char);
int free_buffer(char *, int *);
int hex_format(char *, unsigned int, char *, int *, char *, int w, int);
int cus_string_format(va_list, char *, int *, char *, int, int);
int add_format(va_list ptr, char *, int *, char *, int, int);
int rot13_string_format(va_list, char *, int *, char *, int, int);
int rev_string_format(va_list, char *, int *, char *, int, int);
int print_flag_if_exist(char *, char *, int *, int w, int ln, int is_ng, int);
int unsigned_long_int(va_list, char *, int *, char *, int, int);
int long_int_format(va_list, char *, int *, char *, int, int);
int upper_long_hex(va_list, char *, int *, char *, int, int);
int lower_long_hex(va_list, char *, int *, char *, int, int);
int long_hex(char *hx, unsigned long, char *, int *, char *, int, int);
int long_octal(va_list, char *, int *, char *, int, int);
int short_octal(va_list, char *, int *, char *, int, int);
int unsigned_short_int(va_list, char *, int *, char *, int, int);
int short_int_format(va_list, char *, int *, char *, int, int);
int upper_short_hex(va_list, char *, int *, char *, int, int);
int lower_short_hex(va_list, char *, int *, char *, int, int);
int _len(char *c);

#endif

