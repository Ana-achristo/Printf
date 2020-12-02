#include "ft_printf.h"

/*int	ft_printfirst(char *value)
{
	int	n_add;

	n_add = 0;
	if(value[0] == '-')
		ft_putchar('-')	;
	if(value[0] == 'x')
	{
		ft_putchar('x');
		ft_putchar('0');
		n_add = 1;
	}
	n_add = n_add + 1;
	return(n_add);
}*/



int	ft_print(char *value, int width, char c, int minus)
{
	int i;
	int l;
	int n_add;

	n_add = 0;
//	if (value[0] == '-' || value [0] == 'x')
//		n_add = ft_printfirst(value);
	l = ft_strlen(value);
	width = width - l;
//	value = ft_substr(value, n_add, (l - n_add));
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
