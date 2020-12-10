#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while(s[i] != '\0')
	{
		ft_putchar(s[i]);
		i = i + 1;
	}
	return (i);
}	

size_t	ft_strlen(const char *s)
{
	int	i;
	size_t	len;

	i = 0;
	len = 0;
	while(s[i] != '\0')
	{
		len = len + 1;
		i++;
	}
	return(len);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	start_copy;

	start_copy = ((size_t)start);
	if (s == 0)
		return (0);
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	i = 0;
	while ((i < len) & (s[start_copy + i] != '\0'))
	{
		sub[i] = s[start_copy + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);

}

char	*ft_strcomplete(const char *s, int precision)
{
	char	*new;
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (s == 0)
		return (0);
	if(s[0] == '-')
		j = 1;
	if((len > 1) & (s[0] == '0') & (s[1]=='x'))
		j = 2;
	len = len - j;
	new = malloc((precision + j + 1) * sizeof(char));
	new[precision + j] = '\0';
	while(i < j)
	{
		new[i] = s[i];
		i++;
	}
	while(i < (precision - len + j))
	{
		new[i] = '0';
		i++;
	}
	while (s[j] != '\0')
	{
		new[i] = s[j];
		j++;
		i++;
	}
	return (new);
}
