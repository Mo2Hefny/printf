#include "main.h"

/**
 * _printf - printf alike
 * @format: buffer
 * Return: size of buffer
 */

int _printf(const char *format, ...)
{
  int len = 0, index = 0, i, j, printed = 0;
  char op[100] = {0}, buffer[1024];
  va_list args;

  if (!format)
    return (-1);
  va_start(args, format);
  for (i = 0, j = 0; format[i]; i++)
  {
    if (format[i] == '%')
    {
      print_buffer(buffer, index);
      index = 0;
      op[j] = format[++i];
      printed = check_conversion(op, args, j++);
      if (printed == -1)
        return (-1);
      len += printed;
    }
    else
    {
      len++;
      buffer[index++] = format[i];
      if (index == 1024)
      {
        print_buffer(buffer, index);
        index = 0;
      }
    }
  }
  print_buffer(buffer, index);
  index = 0;
  va_end(args);
  return (len);
}