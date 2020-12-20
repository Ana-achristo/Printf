#include "ft_printf.h"

char	*ft_value_p(char *value_numb)
{
	char	*value;
	int		i;
	int		len;

	len = ft_strlen(value_numb);
	if (!(value = malloc((len + 3) * sizeof(char))))
		return (NULL);
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

char	*ft_strdup(char *s)
{
	char	*s_copy;
	int		len;
	int		i;

	len = ft_strlen(s);
	if (!(s_copy = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}

int		ft_printf_p(t_flags param, va_list lst, char a)
{
	unsigned long int	value_p;
	char				*aux;
	char				*value;
	int					n_add;
	char				*value_new;

	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_p = va_arg(lst, unsigned long int);
	aux = ft_itoa_base(value_p, 16, a);
	if ((value_p == 0) & (param.dot == 1) & (param.precision == 0))
		value = ft_strdup("0x");
	else
		value = ft_value_p(aux);
	value_new = ft_strcomplete(value, param.precision);
	if ((param.zero == 1) & (param.dot == 0))
		n_add = ft_print(value_new, param.width, '0', param.minus);
	else
		n_add = ft_print(value_new, param.width, ' ', param.minus);
	free(value);
	free(aux);
	free(value_new);
	return (n_add);
}
