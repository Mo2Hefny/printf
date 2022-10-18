#include "main.h"

/**
 * _printf - printf alike
 * @format: buffer
 * Return: size of buffer
 */

int _printf(const char *format, ...)
{
int printed, len = 0, index = 0, ind = 0, i, j = 0;
char buff[1024], op[100] = {0};
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
print_buffer(buff, &ind);
printed = check_conversion(op, args, j++);
if (printed == -1)
return (-1);
len += printed;
i++;
}
else
{
buff[ind++] = fotmat[i];
print_buffer(buffer, &ind);
}
}
va_end(args);
return (len);
}
