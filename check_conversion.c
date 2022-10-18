#include "main.h"

/**
 * check_conversion - check conversion letter after %
 * @c: letter
 * Return: size
 */

int check_conversion(char *op, va_list args, int index)
{
  char *s = NULL, c;
  int i, n;
  for (i = 0; i <= index && op[i]; i++)
  {
    switch (*(op + i))
    {
    case 'c':
      c = va_arg(args, int);
      if (i == index)
      {
      print_buffer(&c, 1);
        return (1);
    }
      break;
    case 's':
      s = va_arg(args, char *);

       if (i == index)
        return (print_str(s));
      break;
    case 'i':
    case 'd':
      n = va_arg(args, int);
      if (i == index)
        return (print_dec(n));
      break;
    case 'x':
    case 'X':
      n = va_arg(args, int);
      if (i == index)
        return (print_hex(n, *(op + i)));
      break;
    case 'b':
      n = va_arg(args, unsigned int);
      if (i == index)
        return (print_binary(n));
      break;
    case '%':
      print_buffer("%", 1);
      return (1);
    default:
      print_buffer("%", 1);
      print_buffer((op + i), 1);
      return (2);
    }
  }

  return (0);
}
