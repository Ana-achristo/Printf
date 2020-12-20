#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len = len + 1;
		i++;
	}
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	start_copy;

	start_copy = ((size_t)start);
	if (s == 0)
		return (0);
	if (!(sub = malloc((len + 1) * sizeof(char))))
		return (NULL);
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

char	*ft_newvalue(const char *s, int new_size, int j, int precision, int len)
{
	int	i;
	char	*new;

	i = 0;
	new = malloc((new_size + 1) * sizeof(char));
	new[new_size] = '\0';
	while (i < j)
	{
		new[i] = s[i];
		i++;
	}
	while (i < (precision - len + j))
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

char	*ft_strcomplete(const char *s, int precision)
{
	char	*new;
	int		len;
	int		j;
	int	new_size;

	j = 0;
	len = ft_strlen(s);
	if (s == 0)
		return (0);
	if (s[0] == '-')
		j = 1;
	if ((len > 1) & (s[0] == '0') & (s[1] == 'x'))
		j = 2;
	len = len - j;
	if (precision > len)
		new_size = precision + j;
	else
		new_size = len + j;
	new = ft_newvalue(s, new_size, j, precision, len);
	return (new);
}
