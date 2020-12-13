#include "ft_printf.h"

char	*ft_value_p(char *value_numb)
{
	char	*value;
	int		i;
	int		len;

	len = ft_strlen(value_numb);
	value = malloc((len + 3) * sizeof(char));
	value[0] = '0';
	value[1] = 'x';
	value[len + 2] = '\0';
	i = 0;
	while (i < len)
	{
		value[i + 2] = value_numb[i];
		i++;
	}
	return (value);
}

int		ft_printf_p(t_flags param, va_list lst, char a)
{
	unsigned long int	value_p;
	char				*value_numb;
	char				*value;
	char				empty;
	int					n_add;

	empty = ' ';
	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_p = va_arg(lst, unsigned long int);
	value_numb = ft_itoa_base(value_p, 16, a);
	value = ft_value_p(value_numb);
	if ((value_p == 0) & (param.dot == 1) & (param.precision == 0))
	{
		value = malloc(3 * sizeof(char));
		value = "0x";
	}
	value = ft_strcomplete(value, param.precision);
	if ((param.zero == 1) & (param.dot == 0))
		empty = '0';
	n_add = ft_print(value, param.width, empty, param.minus);
	return (n_add);
}
