#include "_printf.h"

/**
 * _char - prints a character
 * @c: The character to be printed
 *
 * Return: The number of characters printed
 */
int _char(int c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _putchar - prints a character
 * @c: The char to be printed
 *
 * Return: The number of characters printed
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _percent - prints a percent
 *
 * Return: The number of characters printed
 */
int _percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * _all - prints all the formats
 * @format: The format to be printed
 * @args: The arguments passed to the function
 * @i: The index of the format
 *
 * Return: The number of characters printed
 */
int _all(const char format, va_list args, int *i)
{
	int length;

	length = 0;
	if (format == '\0')
		return (0);
	if (format == 'c')
		length += _char(va_arg(args, int));
	else if (format == 's')
		length += _printstr(va_arg(args, char *));
	else if (format == 'p')
		length += _ptr((unsigned long)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		length += _printnbr(va_arg(args, int));
	else if (format == 'u')
		length += _handle_uns(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += _hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += _percent();
	else
		length += _char(format);
	(*i)++;
	return (length);
}

/**
 * _printf - prints a string with formats
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _printf(const char *str, ...)
{
	int i;
	va_list args;
	int length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += _all(str[i + 1], args, &i);
			i++;
		}
		else
		{
			length += _char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (length);
}

