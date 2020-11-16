#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char* s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i = i + 1;
	}
}

int	ft_isspecial(char c)
{
	if (c == '%' || c == '\n')
		return (1);
	return(0);
}


void	ft_format_read(const char *s, va_list lst)
{
	int 	i;
	int	class;
	char	*value_s;
	int	value_d;
	char	value_c;
	unsigned int	value_u;
	int	value_x;

	while(s[i] != '\0')
	{
		if (s[i] == '%')
		{
			class = s[i + 1];
			if (class == 's')
			{
				value_s = va_arg(lst, char*);
				ft_putstr(value_s);
			}
			else if (class == 'd')
			{
				value_d = va_arg(lst, int);
				ft_putstr(ft_itoa(value_d));
			}
			else if (class == 'c')
			{
				value_c = va_arg(lst, int);
				ft_putchar(value_c);
			}
			else if (class == 'u')
			{
				value_u = va_arg(lst, unsigned int);
				ft_putstr(ft_itoa_unsigned(value_u));
			}
			else if (class == 'x')
			{
				value_x = va_arg(lst, int);
				ft_putstr(ft_itoa_base(value_x, 16));
			}
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
	}

}

int printf_ana(const char *format,...)
{
	va_list	lst;

	va_start(lst, format);
	ft_format_read(format, lst);
	va_end(lst);
	return(0);
}

int main()
{	
	int a = 0xE7;
	int b = 0xABCDEF;
	int c = 0xA9B8;
	printf_ana("Meu_Printf=%x, %x, %x\n",a, b, c);
	printf("Printf_Oficial=%x, %x, %x\n", a,b, c);
	return (0);
}
