#include "main.h"

/**
 * print_str - prints string
 * @s: string
 * Return: size of buffer
 */

int print_str(char *s)
{
int len = 0;
while (s[len++])
;
if (print_buffer(s, --len) == -1)
return (-1);
return (len);
}

/**
 * print_dec - prints number
 * @n: number
 * Return: size of buffer
 */

int print_dec(int n)
{
int len = 1;
char dig;
if (n < 0)
{
print_buffer("-", 1);
len++;
n *= -1;
}
dig = '0' + n % 10;
if (n >= 10)
len += print_dec(n / 10);
if (print_buffer(&dig, 1) == -1)
return (-1);
return (len);
}

/**
 * print_hex - prints hexadecimal number
 * @dec: decimal number
 * @lettercase: uppercase or lowercase
 * Return: size of buffer
 */

int print_hex(int dec, char lettercase)
{
int len = 0, Q, R, i;
char hexadecimal[100];
Q = dec;
while (Q > 0)
{
R = Q % 16;
if (R < 10)
hexadecimal[len++] = '0' + R;
else if (lettercase == 'x')
hexadecimal[len++] = 87 + R;
else
hexadecimal[len++] = 55 + R;
Q /= 16;
}
for (i = len; i >= 0; i--)
print_buffer(&hexadecimal[i], 1);
return (len);
}

/**
 * print_binary - prints number in base 10
 * @n: number
 * Return: size of buffer
 */

int print_binary(unsigned int n)
{
int first = 0, i = 0, len;
char bin[32];
unsigned int m = 2147483648;
bin[0] = (n / m) + '0';
for (i = 1; i < 32; i++)
{
m /= 2;
bin[i] = ((n / m) % 2) + '0';
}
for (i = 0, len = 32; i < 32; i++)
{
if (bin[i] == '1')
first = 1;
if (first)
{
printf("entered at: %d\n", i);
len -= i;
if (print_buffer((bin + i), len) == -1)
return (-1);
break;
}
}
return (len);
}

/**
 * print_unsigned - prints number
 * @n: number
 * Return: size of buffer
 */

int print_unsigned(unsigned int n)
{
int len = 1;
char dig = '0' + n % 10;
if (n >= 10)
len += print_dec(n / 10);
if (print_buffer(&dig, 1) == -1)
return (-1);
return (len);
}