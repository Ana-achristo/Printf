#include "ft_printf.h"

int	ft_printf_s(t_flags param, va_list lst)
{
	char	*value;
	char	empty;
	int		n_add;

	empty = ' ';
	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value = va_arg(lst, char*);
	if (value == NULL)
		value = "(null)";
	if (param.dot == 1)
		value = ft_substr(value, 0, param.precision);
	if ((param.zero == 1) & (param.dot == 0))
		empty = '0';
	n_add = ft_print(value, param.width, empty, param.minus);
	return (n_add);
}
