#include "main.h"
/**
 *print_second_hexadecimal - prints hexadecimal nums
 *@num: to be printed
 *@counter: counts
 *Return: returns counter
 */
int print_second_hexadecimal(unsigned int num, int counter)
{
	char hexadecimal_num[100];
	int i = 0;
	int j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			hexadecimal_num[i] = remainder + '0';
		else
			hexadecimal_num[i] = remainder + 'A' - 10;
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		my_putchar('0');
		counter++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			my_putchar(hexadecimal_num[j]);
			counter++;
		}
	}
	return (counter);
}

/**
 *addr_printer - print addrs
 *@addr: adress to be printed
 *@counter: counts
 *Return: counter
 */

int addr_printer(void *addr, int counter)
{
	int i;
	int hex_digit;
	int printed_prefix = 0;
	unsigned long int address;

	if (addr == NULL)
	{
		counter = my_str_printer("(nil)", counter);
		return (counter);
	}
	address = (unsigned long int)addr;
	my_putchar('0');
	my_putchar('x');
	counter += 2;
	for (i = (sizeof(void *) * 2) - 1; i >= 0; i--)
	{
		hex_digit = (address >> (i * 4)) & 0xf;
		if (hex_digit || printed_prefix)
		{
			my_putchar(hex_digit < 10 ? '0' + hex_digit : 'a' + (hex_digit - 10));
			printed_prefix = 1;
			counter++;
		}
	}
	if (!printed_prefix)
	{
		my_putchar('0');
		counter++;
	}
	return (counter);
}

/**
 *rev_str_printer - a function that prints a string in reverse.
 *@s: pointer to a string
 *@counter: counts
 *Return: counter
 */

int rev_str_printer(char *s, int counter)
{
	int i = my_strlen(s);
	int a;

	if (s == NULL)
	{
		counter = my_str_printer("(nil)", counter);
		return (counter);
	}

	for (a = i - 1; a >= 0; a--)
	{
		my_putchar(s[a]);
		counter++;
	}
	return (counter);
}

/**
 *rot13 - rotate 13 time
 *@str: string to be rotated
 *@counter: counts
 *Return: counter
 */

int rot13(char *str, int counter)
{
	int i, len;
	char ch;
	char rot_upchr[26] = {"NOPQRSTUVWXYZABCDEFGHIJKLM"};
	char rot_lwchr[26] = {"nopqrstuvwxyzabcdefghijklm"};

	if (str == NULL)
	{
		counter = my_str_printer("(nil)", counter);
		return (counter);
	}
	len = my_strlen(str);
	for (i = 0; i < len; i++)
	{
		ch = str[i];
		if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
		{
			if (ch >= 97 && ch <= 122)
			{
				ch = rot_lwchr[ch - 'a'];
			}
			else
			{
				ch = rot_upchr[ch - 'A'];
			}
		}
		my_putchar(ch);
		counter++;
	}
	return (counter);
}