#include <unistd.h>
#include <stdarg.h>

void ft_print_char(char c, int *len)
{
	write (1, &c, 1);
	*len = *len + 1;
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return(0);
	while (str[i] != '\0')
		i++;
	return (i);
}
void ft_print_str(char *str, int *len)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		write (1, "null", 6);
		*len = *len + 6;
		return ;
	}
	while(i < ft_strlen(str))
	{
		ft_print_char(str[i], len);
		i++;
	}
	return ;
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_print_str("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_print_char('-', len);
		ft_putnbr(-n, len);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_print_char(n % 10 +'0', len);

}

void	ft_print_hex(unsigned int n, int *len)
{
	char *hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_print_hex(n / 16, len);
	ft_print_char(hex[n % 16], len);
}

void	ft_parse_format(char c, va_list ap, int *len)
{
	if (c == 's')
		ft_print_str(va_arg(ap, char *), len);
	else if (c == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (c == 'x')
		ft_print_hex(va_arg(ap, unsigned int), len);
}

int ft_printf(const char *format, ... )
{
	va_list ap;
	int len;
	int i;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_print_char(format[i], &len);
		else if (format[i] == '%')
			ft_parse_format(format[++i],ap, &len);
		i++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("\n");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}