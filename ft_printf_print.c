#include "ft_printf.h"

void	ft_print(char *value, int width, char c, int minus)
{
	int i;
	int l;

	l = ft_strlen(value);
	width = width - l;
	i = 0;
	if (minus == 1)
		ft_putstr(value);
	while(i < width)
	{
		ft_putchar(c);
		i++;
	}
	if (minus == 0)
		ft_putstr(value);
}
