#include "printf.h"

void	ft_print_width_c(char value, int width, char c, int minus)
{
	int i;
	
	i = 1;
	if (minus == 1)
		ft_putchar(value);
	while (i < width)
	{
		ft_putchar(c);
		i++;
	}
	if (minus == 0)
		ft_putchar(value);

}

int ft_printf_c(t_flags param, va_list lst)
{
	char	value;
	char	empty;

	empty = ' ';
	if (param.starw == 1)
		param.width = va_arg(lst, int);
	value = va_arg(lst, int);
	if (param.zero == 1)
		empty = '0';
	ft_print_width_c(value, param.width, empty, param.minus); 
	return (0);	
}
