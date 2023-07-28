#include "_printf.h"

/**
 * _num_len - calculates the length of a number
 * @num: The number to be measured
 *
 * Return: The length of the number
 */
int	_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

/**
 * _uitoa - converts an unsigned int to a string
 * @n: The number to be converted
 *
 * Return: The string representation of the number
 */
char	*_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = _num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

/**
 * _handle_uns - prints an unsigned int
 * @n: The number to be printed
 *
 * Return: The number of digits printed
 */
int	_handle_uns(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = _uitoa(n);
		length += _printstr(num);
		free(num);
	}
	return (length);
}

