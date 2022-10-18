#include "main.h"

/**
 * print_str - prints string
 * @s: string
 * Return: size of buffer
 */

int print_str(char *s)
{
int len = 0, n;
while (s[len])
len++;
return (print_buffer(&s[0], len));
}

/**
 * print_dec - prints number
 * @n: number
 * Return: size of buffer
 */

int print_dec(int n)
{
int l = 1, len = 1;
char c;
if (n < 0)
{
print_buffer("-", &l);
len++;
n = -n;
}
if (n >= 10)
len += print_dec(n / 10);
c = '0' + n % 10;
print_buffer(&c, &l);
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
int len = 0, Q, R, i, l = 1;
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
print_buffer(&hexadecimal[i], &l);
return (len);
}

/**
 * print_binary - prints number in base 10
 * @n: number
 * Return: size of buffer
 */

int print_binary(int n)
{
int len = 0, i = 0, l = 1;
char bin[100];
if (n == 0)
{
print_buffer("0", &l);
return (1);
}
while (n != 0)
{
if (n % 2)
bin[i++] = 1 + '0';
else
bin[i++] = 0 + '0';
len++;
n /= 2;
}
for (--i; i >= 0; i--)
print_buffer(&bin[i], &l);
return (len);
}
