#include "_printf.h"

/**
 * _ptr_len - calculates the length of a number
 * @num: The number to be measured
 *
 * Return: The length of the number
 */
int	_ptr_len(unsigned long num)
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
 * _put_ptr - prints a number
 * @num: The number to be printed
 *
 * Return: The number of digits printed
 */
void	_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		_put_ptr(num / 16);
		_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			_putchar((num + '0'));
		else
			_putchar((num - 10 + 'a'));
	}
}

/**
 * _ptr - prints a pointer
 * @ptr: The pointer to be printed
 *
 * Return: The number of digits printed
 */
int	_ptr(unsigned long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		_put_ptr(ptr);
		length += _ptr_len(ptr);
	}
	return (length);
}

