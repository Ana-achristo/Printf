#include "printf.h"

void	ft_printf_x(t_flags param, va_list lst, char a)
{
	int	value_x;
	char	*value;
	char	empty;

	empty = ' ';
	if(param.starw == 1)
		param.width = va_arg(lst, int);
	if(param.starp == 1)
		param.precision = va_arg(lst, int);
	value_x = va_arg(lst, int);
	value = ft_itoa_base(value_x, 16, a);
	if(param.precision != 0)
		value = ft_substr(value, 0, param.precision);
	if(param.zero == 1)
		empty = '0';
	ft_print(value, param.width, empty, param.minus);
}
