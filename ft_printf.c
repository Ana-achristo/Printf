#include "ft_printf.h"

int	ft_putdata(t_flags param, va_list lst)
{
	int n_add;

	n_add = 0;
	if(param.converter == 'c')
		n_add = ft_printf_c(param, lst);
	if(param.converter == 's')
		n_add = ft_printf_s(param, lst);
	if(param.converter == 'd' || param.converter == 'i')
		n_add = ft_printf_d(param, lst);
	if(param.converter == 'u')
		n_add = ft_printf_u(param, lst);
	if(param.converter == 'x')
		n_add = ft_printf_x(param, lst, 'a');
	if(param.converter == 'X')
		n_add = ft_printf_x(param, lst, 'A');
	if(param.converter == 'p')
		n_add = ft_printf_p(param, lst, 'a');
	if(param.converter == '%')
		n_add = ft_printf_c(param, lst);
	return (n_add);
}


int	ft_format_read(const char *s, va_list lst)
{
	int i;
	int n;
	t_flags	param;

	i = 0;
	n = 0;
	param.converter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			param = ft_flags_init(param);
			param = ft_identify(s, i, param);
			i = param.position;	
			n = n + ft_putdata(param, lst);
		}
		else
		{
			ft_putchar(s[i]);
			n = n + 1;
		}
		i++;
	}
	return (n);
}


int ft_printf(const char *format,...)
{
	va_list	lst;
	int n;

	va_start(lst, format);
	n = ft_format_read(format, lst);
	va_end(lst);

	return (n);
}
