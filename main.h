#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct f_list
{
char *sym;
int (*f)(va_list);
} conver_t;

int print_buffer(char *s, int size);
int _printf(const char *format,...);
int parser(const char *format, conver_t f_list[], va_list arg_list);

int print_char(va_list list);
int print_string(va_list list);
int print_string_custom(va_list list);
int print_percent(va_list list);
int print_int(va_list list);
int print_unsigned(va_list list);
int print_octa(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);
int print_address(va_list list);
int print_str_custom(va_list list);
int print_reverse(va_list list);
int print_rot13(va_list list);
int print_binary(va_list list);
int print_number(va_list args);
int print_unsigned_number(unsigned int n);

int hex_check(int, char);
int base_len(int num, int base);
int hex_2dig(int);

#endif
