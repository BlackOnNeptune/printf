#include <unistd.h>

/**
 * my_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *my_str_printer - prints a string
 *@str: string to be printed
 *@counter: counts
 *Return: returns
 */

int my_str_printer(char *str, int counter)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		my_putchar(*str);
		str++;
		counter++;
	}
	return (counter);
}

/**
 *my_strchar - search for a char in a str
 *@str: str that will be compared
 *@c: char that is compared
 *Return: i or -1
 */

int my_strchar(char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

/**
 *my_strlen - counts
 *@s: string or smtg
 *Return: counter
 */

int my_strlen(const char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

/**
 *spcl_chr - prints the non printable chr
 *@s: string to be converted
 *@counter: counts
 *Return: returns
 */

int spcl_chr(const char *s, int counter)
{
	while (*s != '\0')
	{
		if (*s < 32 || *s >= 127)
		{
			my_putchar('\\');
			my_putchar('x');
			my_putchar((*s / 16) + '0');
			my_putchar((*s % 16) + ((*s % 16 < 10) ? '0' : 'A' - 10));
			counter += 4;
		}
		else
		{
			my_putchar(*s);
			counter++;
		}
		s++;
	}
	return (counter);
}