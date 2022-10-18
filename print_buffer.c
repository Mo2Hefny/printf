#include <unistd.h>
/**
 * print_buffer - writes the character c
 * @s: The characters to print
 * @size: size
 * Return: On success 1.
 * On error, -1 is returned.
 */
int print_buffer(char s[], int size)
{
	if (size > 0)
	return(write(1, &s[0], size));
	
}