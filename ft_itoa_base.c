#include "ft_printf.h"

int		ft_size_number_b(unsigned long int n, int base)
{
	int size;

	size = 0;
	while ((n / base) > 0)
	{
		size = size + 1;
		n = n / base;
	}
	size = size + 1;
	return (size);
}

char	*ft_itoa_base(unsigned long int n, int base, char a)
{
	int		size;
	char	*s;

	size = ft_size_number_b(n, base);
	s = malloc((size + 1) * sizeof(char));
	if (s == 0)
		return (0);
	s[size] = '\0';
	size = size - 1;
	while (size >= 0)
	{
		if ((n % base) <= 9)
			s[size] = n % base + 48;
		else
			s[size] = n % base + a - 10;
		n = n / base;
		size--;
	}
	return (s);
}
