#include <unistd.h>
/**
 * print_buffer - writes the character c
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int print_buffer(char c)
{
return (write(1, &c, 1));
}
