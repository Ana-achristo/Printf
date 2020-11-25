#include "printf.h"

int ft_printf_c(t_flags param, va_list lst)
{
	char	value;
	int	i;

	i = 0;
	if (param.precision != 0 || param.zero != 0)
		return (1);
	value = va_arg(lst, int);
	if (param.minus == 1)
	{
		ft_putchar(value);
		while (i < param.width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i < param.width)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar(value);
	}
	return (0);	
}
