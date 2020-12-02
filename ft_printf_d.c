#include "ft_printf.h"

t_flags	ft_read_star(va_list lst, int worp, t_flags param)
{
	int num;

	num = va_arg(lst, int);
	if (worp == 0)
	{
		if(num < 0)
		{
			param.minus = 1;
			num = num * -1;
		}
		if(param.minus == 1)
			param.zero = 0;
		param.width = num;
	}
	else
	{
		if (num < 0)
		{
			num = 0;
			param.dot = 0;
		}
		param.precision = num;
	}
	return (param);
}



int	ft_printf_d(t_flags param, va_list lst)
{
	int	value_d;
	char	*value;
	char	empty;
	int	n_add;

	empty = ' ';
	if(param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if(param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_d = va_arg(lst, int);
	value = ft_itoa(value_d);
	if ((value_d == 0) & (param.dot == 1) & (param.precision == 0))
		value = ft_substr(value, 0, 0);
	//if(param.precision > ft_strlen(value))
	value = ft_strcomplete(value, param.precision);
	if((param.zero == 1) & (param.dot == 0))
		empty = '0';
	n_add = ft_print(value, param.width, empty, param.minus);
	return (n_add);
}
