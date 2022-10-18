#include "main.h"

/**
 * print_reverse - prints string backwards
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int print_reverse(va_list list)
{
int len = 0, i;
char *s;

s = va_arg(list, char *);
if (s == NULL)
s = "(null)";
while (s[len++])
;
for (i = --len; i >= 0; i--)
print_buffer(&s[i], 1);
return (len);
}

/**
 * print_octa - prints octagonal number
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int print_octa(va_list list)
{
unsigned long int num;
int len, i;
int rem_num;
char *octa_rep;
num = va_arg(list, unsigned long int);
if (num == 0)
return (print_buffer("0", 1));
if (num < 1)
return (-1);
len = base_len(num, 8);
octa_rep = malloc(sizeof(char) * len + 1);
if (octa_rep == NULL)
return (-1);
for (len = 0; num > 0; len++)
{
rem_num = num % 8 + '0';
octa_rep[len] = rem_num;
num /= 8;
}
octa_rep[len] = '\0';
for (i = len - 1; i >= 0; i--)
{
  print_buffer(&octa_rep[i], 1);
}
free(octa_rep); 
return (len);
}

/**
 * print_rot13 - prints string in rot13 encryption
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int print_rot13(va_list list)
{
int i, j;
char *s;
char in[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIGKLMnopqrstuvwxyzabcdefghijklm";

s = va_arg(list, char *);
if (s == NULL)
s = "(null)";
for (i = 0; s[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == s[i])
{
print_buffer(&out[j], 1);
break;
}
}
if (!in[j])
{
print_buffer(&s[i], 1);
}
}
return (i);
}

/**
 * print_binary - prints number in base 10
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int print_binary(va_list list)
{
unsigned int n;
int first = 0, i = 0, len;
char bin[32];
unsigned int m;

n = va_arg(list, unsigned int);
m = 2147483648;
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
if (first || i == 31)
{
len -= i;
if (print_buffer((bin + i), len) == -1)
return (-1);
break;
}
}
return (len);
}

/**
 * print_percent - prints perncent
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int print_percent(va_list list)
{
(void)list;
return (write(1, "%%", 1));
}