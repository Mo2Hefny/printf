#include "main.h"
/* for commits */
/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */

int print_number(va_list args)
{
int n;
int div;
int len;
char c;
unsigned int num;

n  = va_arg(args, int);
div = 1;
len = 0;

if (n < 0)
{
len += print_buffer("-", 1);
num = n * -1;
}
else
num = n;

for (; num / div > 9; )
div *= 10;

for (; div != 0; )
{
c = '0' + num / div;
len += print_buffer(&c, 1);
num %= div;
div /= 10;
}
return (len);
}

/**
 * print_unsgined_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */

int print_unsigned_number(unsigned int n)
{
int div;
int len;
unsigned int num;
char c;
div = 1;
len = 0;

num = n;

for (; num / div > 9; )
div *= 10;

for (; div != 0; )
{
c = '0' + num / div;
len += print_buffer(&c, 1);
num %= div;
div /= 10;
}

return (len);
}
