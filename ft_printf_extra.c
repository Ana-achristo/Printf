#include "ft_printf.h"

int	ft_isclass(char c)
{
	char	*class;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!(class = ft_strdup("cspdiuxX%")))
		return (0);
	while (i < 9)
	{
		if (class[i] == c)
			res = 1;
		i++;
	}
	return (res);
}

int	ft_isnumber(char c)
{
	char	*numbers;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!(numbers = ft_strdup("0123456789")))
		return (0);
	while (i < 10)
	{
		if (numbers[i] == c)
			res = 1;
		i++;
	}
	return (res);
}
