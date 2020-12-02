#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
	{
		ft_putchar(s[i]);
		i = i + 1;
	}
	return (i);
}	

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return(i);
}

char *ft_substr(char *s, int start, int len)
{
	char *sub;
	int i;
	
	sub = malloc((len + 1) * sizeof(char));
	sub[len] = '\0';
	i = 0;
	while ((i < len) & (s[start + i] != '\0'))
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);

}
