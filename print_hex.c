#include "main.h"
#include <stdio.h>

/**
 * print_heX - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */

int print_heX(va_list list)
{
unsigned int num;
int len, i;
int rem_num;
char *hex_rep;
num = va_arg(list, unsigned int);
if (num == 0)
return (print_buffer("0", 1));
if (num < 1)
return (-1);
len = base_len(num, 16);
hex_rep = malloc(sizeof(char) * len + 1);
if (hex_rep == NULL)
return (-1);
for (len = 0; num > 0; len++)
{
rem_num = num % 16;
if (rem_num > 9)
{
rem_num = hex_check(rem_num, 'X');
hex_rep[len] = rem_num;
}
else
hex_rep[len] = rem_num + 48;
num /= 16;
}
hex_rep[len] = '\0';
for (i = len - 1; i >= 0; i--)
{
  print_buffer(&hex_rep[i], 1);
}
free(hex_rep); 
return (len);
}

/**
 * print_hex - Prints a representation of a decimal number on base16 Lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */

int print_hex(va_list list)
{
unsigned int num;
int len, i;
int rem_num;
char *hex_rep;
num = va_arg(list, unsigned int);
if (num == 0)
return (print_buffer("0", 1));
if (num < 1)
return (-1);
len = base_len(num, 16);
hex_rep = malloc(sizeof(char) * len + 1);
if (hex_rep == NULL)
return (-1);
for (len = 0; num > 0; len++)
{
rem_num = num % 16;
if (rem_num > 9)
{
rem_num = hex_check(rem_num, 'x');
hex_rep[len] = rem_num;
}
else
hex_rep[len] = rem_num + 48;
num /= 16;
}
hex_rep[len] = '\0';
for (i = len - 1; i >= 0; i--)
{
  print_buffer(&hex_rep[i], 1);
}
free(hex_rep);
return (len);
return (len);
}


/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */

int hex_check(int num, char x)
{
char *hex = "abcdef";
char *Hex = "ABCDEF";
num = num - 10;
if (x == 'x')
return (hex[num]);
else
return (Hex[num]);
return (0);
}


/**
 * base_len - get length of base
 * @num: Number
 * @base: base of number
 * Return: length
 */

int base_len(int num, int base)
{
int count = 1;
while (num > 0)
{
num /= base;
count++;
}
return (count);
}