#include "main.h"

/**
 * _printf - printf alike
 * @format: buffer
 * Return: size of buffer
 */

int _printf(const char *format, ...)
{
int len = 0, index = 0, i, j = 0;
char op[100] = {0};
va_list args;

if (!format)
return (-1);
while (format[index])
if (format[index++] != '%')
len++;
else
{
op[j++] = format[index++];
}
j = 0;
va_start(args, format);
for (i = 0; format[i]; i++)
{
if (format[i] == '%')
{
len += check_conversion(op, args, j++);
i++;
}
else
{
print_buffer(format[i]);
}
}
va_end(args);
return (len);
}
