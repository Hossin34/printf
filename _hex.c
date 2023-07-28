#include "_printf.h"

/**
 * _hex_len - calculates the length of a number
 * @num: The number to be measured
 *
 * Return: The length of the number
 */
int	_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

/**
 * _put_hex - prints a hex number
 * @num: The number to be printed
 * @format: The format to be printed
 *
 * Return: The number of digits printed
 */
void	_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		_put_hex(num / 16, format);
		_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			_putchar((num + 48));
		else
		{
			if (format == 'x')
				_putchar((num - 10 + 97));
			if (format == 'X')
				_putchar((num - 10 + 65));
		}
	}
}

/**
 * _hex - prints a hex number
 * @num: The number to be printed
 * @format: The format to be printed
 *
 * Return: The number of digits printed
 */

int	_hex(unsigned int num, const char format)
{
	if (num != 0)
		_put_hex(num, format);

	else
		return (write(1, "0", 1));
	return (_hex_len(num));
}
