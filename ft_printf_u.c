#include "ft_printf.h"

int	ft_printf_u(t_flags param, va_list lst)
{
	int	value_u;
	char	*value;
	char	empty;
	int	n_add;

	empty = ' ';
	if(param.starw == 1)
		param.width = va_arg(lst, int);
	if(param.starp == 1)
		param.precision = va_arg(lst, int);
	value_u = va_arg(lst, unsigned int);
	value = ft_itoa_unsigned(value_u);
	if(param.precision != 0)
		value = ft_substr(value, 0, param.precision);
	if(param.zero == 1)
		empty = '0';
	n_add = ft_print(value, param.width, empty, param.minus);
		return (n_add);
}
