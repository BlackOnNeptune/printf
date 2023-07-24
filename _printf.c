#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format
 * @format: character string containing directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
{
	if (*format == '%')
{
	format++; /* Move past '%' */
	switch (*format)
{
	case 'c':
	/* char is promoted to int when passed through va_args */
	_putchar(va_arg(args, int));
	count++;
	break;
	case 's':
{
	char *str = va_arg(args, char *);
	if (str == NULL)
	str = "(null)";
	while (*str != '\0')
{
	_putchar(*str);
	str++;
	count++;
}
	break;
}
	case '%':
	_putchar('%');
	count++;
	break;
	default:
	_putchar('%');
	_putchar(*format);
	count += 2;
}
}
	else
	{
	_putchar(*format);
	count++;
}
	format++;
}

	va_end(args);
	return (coun)t;
}

