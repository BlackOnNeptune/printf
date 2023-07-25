#include "main.h"

/**
 *my_switch - switch between cases
 *@args: arguments
 *@format: list of argument types
 *@counter: counter
 *Return: retrns counter
 */

int my_switch(va_list args, char format, int counter)
{
	switch (format)
	{
		case '%':
			my_putchar('%');
			counter++;
			break;
		case 'c':
			my_putchar(va_arg(args, int));
			counter++;
			break;
		case 's':
			counter = my_str_printer(va_arg(args, char *), counter);
			break;
		case 'd':
		case 'i':
			counter = my_int_printer(va_arg(args, int), counter);
			break;
		case 'b':
			counter = print_binary(va_arg(args, int), counter);
			break;
		case 'S':
			counter = spcl_chr(va_arg(args, char *), counter);
			break;
		default:
			return (second_switch(args, format, counter));
	}
	return (counter);
}

/**
 *second_switch - our second switch that goes between cases
 *@args: arguments
 *@format: list of argument types
 *@counter: counter
 *Return: returns counter
 */

int second_switch(va_list args, char format, int counter)
{
	switch (format)
	{
		case 'u':
			counter = unsigned_int_printer(va_arg(args, int), counter);
			break;
		case 'o':
			counter = print_octal(va_arg(args, int), counter);
			break;
		case 'x':
			counter = print_hexadecimal(va_arg(args, int), counter);
			break;
		case 'X':
			counter = print_second_hexadecimal(va_arg(args, int), counter);
			break;
		case 'p':
			counter = addr_printer(va_arg(args, void *), counter);
			break;
		case 'r':
			counter = rev_str_printer(va_arg(args, char *), counter);
			break;
		case 'R':
			counter = rot13(va_arg(args, char *), counter);
			break;
		default:
			my_putchar('%');
			my_putchar(format);
			counter += 2;
			break;
	}
	return (counter);
}