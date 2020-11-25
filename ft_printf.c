#include "printf.h"

/*int	ft_isspecial(char c)
{
	if (c == '%' || c == '\n')
		return (1);
	return(0);
}


void	ft_format_read(const char *s, va_list lst)
{
	int 	i;
	int	class;
	char	*value_s;
	int	value_d;
	char	value_c;
	unsigned int	value_u;
	int	value_x;
	char	a;

	while(s[i] != '\0')
	{
		if (s[i] == '%')
		{
			class = s[i + 1];
			if (class == 's')
			{
				value_s = va_arg(lst, char*);
				ft_putstr(value_s);
			}
			else if (class == 'd')
			{
				value_d = va_arg(lst, int);
				ft_putstr(ft_itoa(value_d));
			}
			else if (class == 'c')
			{
				value_c = va_arg(lst, int);
				ft_putchar(value_c);
			}
			else if (class == 'u')
			{
				value_u = va_arg(lst, unsigned int);
				ft_putstr(ft_itoa_unsigned(value_u));
			}
			else if (class == 'x')
			{
				a = 'a';
				value_x = va_arg(lst, int);
				ft_putstr(ft_itoa_base(value_x, 16, a));
			}
			else if (class == 'X')
			{
				a = 'A';
				value_x = va_arg(lst, int);
				ft_putstr(ft_itoa_base(value_x, 16, a));
			}
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
	}

}*/

void	ft_putdata(t_flags param, va_list lst)
{
	int error;

	if (param.converter == 'c')
	{
		error = ft_printf_c(param, lst);
	}
}


void	ft_format_read(const char *s, va_list lst)
{
	int i;
	t_flags	param;

	i = 0;
	param = ft_flags_init(param);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			param = ft_identify(s, i, param);
			i = param.position;
			ft_putdata(param, lst);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
}


void ft_printf(const char *format,...)
{
	va_list	lst;

	va_start(lst, format);
	ft_format_read(format, lst);
	va_end(lst);
}

int main()
{	
	int a = 12345;
	char *s = "xxx";
	char c;

	c = s[0];

	ft_printf("R=%4c\n",c);

//	printf("Printf_Oficial=%d\n", a);

	return (0);
}
