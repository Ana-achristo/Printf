#include "ft_printf.h"

int		ft_size_number(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		n = n + 1;
	if (n < 0)
	{
		size = size + 1;
		n = n * -1;
	}
	while (n / 10 > 0)
	{
		size = size + 1;
		n = n / 10;
	}
	size = size + 1;
	return (size);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*s;

	size = ft_size_number(n);
	s = malloc((size + 1) * sizeof(char));
	if (s == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	s[size] = '\0';
	size = size - 1;
	while (size >= i)
	{
		if (n < 0)
			s[size] = (n % 10) * -1 + 48;
		else
			s[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (s);
}
