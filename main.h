#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int print_buffer(char *s, int *size);
int check_conversion(char *op, va_list args, int index);

int print_char(char c);
int print_str(char *s);
int print_dec(int n);
int print_int(int n);
int print_binary(int n);
int print_unsigned(int n);
int print_octa(int n);
int print_hex(int n, char lettercase);
int print_address(char c);
int print_str_custom(char *s);
int print_rev(char *s);
int print_rot13(char *s);

#endif
