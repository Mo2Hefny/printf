#include "main.h"
/* for commits */
/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */

int parser(const char *format, conver_t f_list[], va_list arg_list)
{
int i, j, r_val, printed_chars = 0, index = 0;
char buffer[1024];

printed_chars = 0;
for (i = 0; format[i] != '\0'; i++)/* Iterates through the main str*/
{
if (format[i] == '%') /*Checks for format specifiers*/
{
print_buffer(buffer, index);
index = 0;
/*Iterates through struct to find the right func*/
for (j = 0; f_list[j].sym != NULL; j++)
{
if (format[i + 1] == f_list[j].sym[0])
{
r_val = f_list[j].f(arg_list);
if (r_val == -1)
return (-1);
printed_chars += r_val;
break;
}
}
if (f_list[j].sym == NULL && format[i + 1] != ' ')
{
if (format[i + 1] != '\0')
{
buffer[index++] = format[i];
buffer[index++] = format[i + 1];
print_buffer(buffer, index);
index = 0;
printed_chars += 2;
}
else
return (-1);
}
i++; /*Updating i to skip format symbols*/
}
else
{
printed_chars++;
buffer[index++] = format[i];
if (index == 1024)
{
print_buffer(buffer, index);
index = 0;
}
}
}
print_buffer(buffer, index);
return (printed_chars);
}
