#ifndef _PRINTF_H
# define _PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		_printf(const char *str, ...);
int		_all(const char format, va_list args, int *i);
int		_char(int c);
void		_putstr(char *str);
int		_printstr(char *str);
int		_printnbr(int n);
int		_percent(void);
int		_handle_uns(unsigned int n);
int		_ptr(unsigned long ptr);
void		_put_hex(unsigned int num, const char format);
int		_hex(unsigned int num, const char format);
void		_putchar(char c);
#endif
