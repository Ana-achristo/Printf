#include "ft_printf.h"

int	ft_print(char *value, int width, char c, int minus)
{
	int i;
	int l;
	int n_add;

	n_add = 0;
	l = ft_strlen(value);
	width = width - l;
	i = 0;
	if (minus == 1)
		n_add = ft_putstr(value);
	while(i < width)
	{
		ft_putchar(c);
		n_add = n_add + 1;
		i++;
	}
	if (minus == 0)
		n_add = n_add + ft_putstr(value);
	return (n_add);
}
