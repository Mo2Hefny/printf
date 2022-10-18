#include "main.h"

/**
 * print_char - Prints character
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_char(va_list list)
{
char c = va_arg(list, int);
if(print_buffer(&c, 1) == 1)
return (1);
return (-1);
}

/**
 * print_string - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_string(va_list list)
{
int i;
char *str;

str = va_arg(list, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
print_buffer(&str[i], 1);
return (i);
}
/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_int(va_list list)
{
int num_length;

num_length = print_number(list);
return (num_length);
}

/**
 * unsigned_integer - Prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */
int print_unsigned(va_list list)
{
unsigned int num;

num = va_arg(list, unsigned int);

if (num == 0)
return (print_unsigned_number(num));

if (num < 1)
return (-1);
return (print_unsigned_number(num));
}
