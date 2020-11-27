#include "printf.h"

/*

void	ft_format_read(const char *s, va_list lst)
{
	int 	i;
	int	class;
	char	*value_s;
	int	value_d;
	char	value_c;
	unsigned int	value_u;
	int	value_x;
	char	a;

	while(s[i] != '\0')
	{
		if (s[i] == '%')
		{
			class = s[i + 1];

			else if (class == 'u')
			{
				value_u = va_arg(lst, unsigned int);
				ft_putstr(ft_itoa_unsigned(value_u));
			}
			else if (class == 'x')
			{
				a = 'a';
				value_x = va_arg(lst, int);
				ft_putstr(ft_itoa_base(value_x, 16, a));
			}
			else if (class == 'X')
			{
				a = 'A';
				value_x = va_arg(lst, int);
				ft_putstr(ft_itoa_base(value_x, 16, a));
			}
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
	}

}*/

void	ft_putdata(t_flags param, va_list lst)
{
	if(param.converter == 'c')
		ft_printf_c(param, lst);
	if(param.converter == 's')
		ft_printf_s(param, lst);
	if(param.converter == 'd')
		ft_printf_d(param, lst);
	if(param.converter == 'u')
		ft_printf_u(param, lst);
}


void	ft_format_read(const char *s, va_list lst)
{
	int i;
	t_flags	param;

	i = 0;
	param = ft_flags_init(param);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			param = ft_identify(s, i, param);
			i = param.position;	
			ft_putdata(param, lst);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
}


void ft_printf(const char *format,...)
{
	va_list	lst;

	va_start(lst, format);
	ft_format_read(format, lst);
	va_end(lst);
}
