#include "main.h"

/**
 * print_string_custom - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_string_custom(va_list list)
{
int i;
char *str;

str = va_arg(list, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] < 32 || str[i] >= 127)
{
print_buffer("\\x", 2);
hex_2dig(str[i]);
}
else
print_buffer(&str[i], 1);
}
return (i);
}

int hex_2dig(int n)
{
int len = 0, Q, R, i;
char hexadecimal[2];
  Q = n;
  while (Q > 0)
  {
    R = Q % 16;
    if (R < 10)
      hexadecimal[len++] = '0' + R;
    else
      hexadecimal[len++] = 55 + R;
    Q /= 16;
  }
  if (len != 2)
  {
    print_buffer("0", 1);
  }
  for (i = len - 1; i >= 0; i--)
    print_buffer(&hexadecimal[i], 1);
  return (len);
}
