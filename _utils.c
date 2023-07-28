#include "_printf.h"

/**
 * _putstr - prints a string
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */

void	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


/**
 * num_length - calculates the length of a number
 * @nb: The number to be measured
 *
 * Return: The length of the number
 */

int	num_length(long nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		l++;
	else if (nb < 0)
	{
		nb = -nb;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

/**
 * _itoa - converts an int to a string
 * @n: The number to be converted
 *
 * Return: The string representation of the number
 */

char	*_itoa(int n)
{
	long	nb;
	char	*ptr;
	int		i;

	nb = n;
	i = num_length(nb);
	ptr = (char *)malloc((num_length(nb) + 1));
	if (!ptr)
		return (NULL);
	ptr[i--] = '\0';
	if (nb == 0)
		ptr[0] = '0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		ptr[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ptr);
}

/**
 * _printstr - prints a string
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */

int	_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * _printnbr - prints a number
 * @n: The number to be printed
 *
 * Return: The number of digits printed
 */

int	_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = _itoa(n);
	len = _printstr(num);
	free(num);
	return (len);
}

