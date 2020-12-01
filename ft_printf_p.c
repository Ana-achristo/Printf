#include "ft_printf.h"

char	*ft_value_p(char *value_numb)
{
	char	*value;
	int	i;
	int	len;
	
	len = ft_strlen(value_numb);
	value = malloc((len + 3) * sizeof(char));
	value[0] = '0';
	value[1] = 'x';
	value[len + 2] = '\0';
	i = 0;
	while(i < len)
	{
		value[i + 2] = value_numb[i];
		i++;
	}
	return (value);
}


void	ft_printf_p(t_flags param, va_list lst, char a)
{
	unsigned long int value_p;
	char	*value_numb;
	char	*value;
	char	empty;

	empty = ' ';
	if(param.starw == 1)
		param.width = va_arg(lst, int);
	if(param.starp == 1)
		param.precision = va_arg(lst, int);
	value_p = va_arg(lst, unsigned long int);
	value_numb = ft_itoa_base(value_p, 16, a);
	value = ft_value_p(value_numb);
	if(param.precision != 0)
		value = ft_substr(value, 0, param.precision);
	if(param.zero == 1)
		empty = '0';
	ft_print(value, param.width, empty, param.minus);
}
