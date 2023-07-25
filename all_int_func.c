#include "main.h"

/**
 *my_int_printer - prints nums
 *@num: to be printed
 *@counter: counts
 *Return: returns
 */

int my_int_printer(int num, int counter)
{
	if (num == INT_MIN)
	{
	my_putchar('-');
	my_putchar('2');
	my_putchar('1');
	my_putchar('4');
	my_putchar('7');
	my_putchar('4');
	my_putchar('8');
	my_putchar('3');
	my_putchar('6');
	my_putchar('4');
	my_putchar('8');
	counter += 11;
	return (counter);
	}
	else if (num < 0)
	{
		my_putchar('-');
		num = -num;
		counter++;
	}
	if (num < 10)
	{
		my_putchar(num + '0');
		counter++;
	}
	else
	{
		counter = my_int_printer(num / 10, counter);
		counter = my_int_printer(num % 10, counter);
	}
	return (counter);
}

/**
 * print_binary - Prints the binary representation of an unsigned int
 * @n: Tnumber
 * @counter: counts
 * Return: returns counter
 */

int print_binary(int n, int counter)
{
	unsigned int num;
	int i, j;
	char binary[32];

	num = n;
	if (num > UINT_MAX)
	{
		my_str_printer("(null)", counter);
		return (counter);
	}
	if (num == 0)
	{
		my_putchar('0');
		counter++;
		return (counter);
	}

	for (i = 0; num > 0; i++)
	{
		binary[i] = (num % 2 == 1) ? '1' : '0';
		num /= 2;
	}
	binary[i] = '\0';

	for (j = i - 1; j >= 0; j--)
	{
		my_putchar(binary[j]);
		counter++;
	}

	return (counter);
}
/**
 *unsigned_int_printer - prints unsigned nums
 *@num: to be printed
 *@counter: counts
 *Return: returns countern
 */
int unsigned_int_printer(unsigned int num, int counter)
{
	if (num < 10)
	{
		my_putchar(num + '0');
		counter++;
	}
	else
	{
		counter = unsigned_int_printer(num / 10, counter);
		counter = unsigned_int_printer(num % 10, counter);
	}
	return (counter);
}
/**
 *print_octal - prints octal nums
 *@num: to be printed
 *@counter: counts
 *Return: returns counter
 */
int print_octal(unsigned int num, int counter)
{
	int octal_num[100];
	int i = 0;
	int j;

	while (num != 0)
	{
		octal_num[i] = num % 8;
		num /= 8;
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
			my_putchar(octal_num[j] + '0');
			counter++;
		}
	}
	return (counter);
}
/**
 *print_hexadecimal - prints hexadecimal nums
 *@num: to be printed
 *@counter: counts
 *Return: returns counter
 */
int print_hexadecimal(unsigned int num, int counter)
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
			hexadecimal_num[i] = remainder + 'a' - 10;
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