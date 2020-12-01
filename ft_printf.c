#include "ft_printf.h"

void	ft_putdata(t_flags param, va_list lst)
{
	if(param.converter == 'c')
		ft_printf_c(param, lst);
	if(param.converter == 's')
		ft_printf_s(param, lst);
	if(param.converter == 'd' || param.converter == 'i')
		ft_printf_d(param, lst);
	if(param.converter == 'u')
		ft_printf_u(param, lst);
	if(param.converter == 'x')
		ft_printf_x(param, lst, 'a');
	if(param.converter == 'X')
		ft_printf_x(param, lst, 'A');
	if(param.converter == 'p')
		ft_printf_p(param, lst, 'a');
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
