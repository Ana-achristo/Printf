#include "ft_printf.h"

int	ft_printf_x(t_flags param, va_list lst, char a)
{
	int	value_x;
	char	*value;
	char	empty;
	int	n_add;

	empty = ' ';
	if(param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if(param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_x = va_arg(lst, int);
	value = ft_itoa_base((unsigned int)value_x, 16, a);
	if((value_x == 0) & (param.dot == 1) & (param.precision == 0))
		value = ft_substr(value, 0, 0);
	//if(param.precision > ft_strlen(value))
	value = ft_strcomplete(value, param.precision);
	if(param.zero == 1)
		empty = '0';
	n_add = ft_print(value, param.width, empty, param.minus);
	return (n_add);
}
