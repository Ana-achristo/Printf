#include "ft_printf.h"

int	ft_printf_u(t_flags param, va_list lst)
{
	int		value_u;
	char	*value;
	char	empty;
	int		n_add;

	empty = ' ';
	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_u = va_arg(lst, unsigned int);
	value = ft_itoa_unsigned(value_u);
	if ((value_u == 0) & (param.dot == 1) & (param.precision == 0))
		value = ft_substr(value, 0, 0);
	value = ft_strcomplete(value, param.precision);
	if ((param.zero == 1) & (param.dot == 0))
		empty = '0';
	n_add = ft_print(value, param.width, empty, param.minus);
	return (n_add);
}
