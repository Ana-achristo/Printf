#include "printf.h"

int	ft_size_number_u(unsigned int n)
{
	int size;

	size = 0;
	while (n / 10 > 0)
	{
		size = size + 1;
		n = n / 10;
	}
	size = size + 1;
	return (size);
}

char *ft_itoa_unsigned(unsigned int n)
{
	int	size;
	char	*s;

	size = ft_size_number_u(n);
	s = malloc((size+1)*sizeof(char));
	if (s == 0)
		return (0);
	s[size] = '\0';
	size = size - 1;
	while (size >= 0)
	{
		s[size] = n % 10 + 48;	
		n = n / 10;
		size--;
	}
	return (s);
}
