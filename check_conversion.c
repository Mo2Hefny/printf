#include "main.h"

/**
 * check_conversion - check conversion letter after %
 * @op: conversion options in format
 * @args: arguments in function
 * @index: number of conversion to check in op array
 * Return: size
 */

int check_conversion(char *op, va_list args, int index)
{
char *s = NULL, c;
int i, n;
for (i = 0; i <= index && op[i]; i++)
{
switch (*(op + i))
{
case 'c':
c = va_arg(args, int);
if (i == index)
return (print_buffer(c));
break;
case 's':
s = va_arg(args, char *);
if (i == index)
return (print_str(s));
break;
case 'd':
case 'i':
n = va_arg(args, int);
if (i == index)
return (print_dec(n));
break;
case 'x':
case 'X':
n = va_arg(args, int);
if (i == index)
return (print_hex(n, *(op + i)));
break;
case 'b':
n = va_arg(args, int);
if (i == index)
return (print_binary(n));
break;
case '%':
print_buffer('%');
return (1);
default:
print_buffer('%');
print_buffer(*(op + i));
return (2);
}
}

return (0);
}
