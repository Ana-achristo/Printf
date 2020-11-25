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


t_flags	ft_flags_init(t_flags param)
{
	param.width = 0;
	param.minus = 0;
	param.zero = 0;
	param.precision = 0;
	param.converter = '0';
	param.newline = 0;
	param.position = 0;	

	return (param);
}

int	ft_isclass(char c)
{
	char	*class = "cspdiuxX%";
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 9)
	{
		if (class[i] == c)
			res = 1;
		i++;
	}
	return (res);
}

t_flags ft_precision(const char *s, int i, t_flags param)
{
	int j;
	int sum;

	j = 2;
	sum = 0;
	while (ft_isclass(s[i + j]) == 0)
	{
		sum = sum * 10 + s[i + j] - '0';
		j++;
	}
	param.precision = sum;
	param.converter = s[i + j];
	param.position = i + j;
	return (param);
}

t_flags ft_width (const char *s, int i, t_flags param)
{
	int j;
	int sum;

	j = 1;
	sum = 0;
	while (ft_isclass(s[i + j]) == 0 & s[i + j] != '.')
	{
		sum = sum * 10 + s[i + j] - '0';
		j++;
	}
	param.width = sum;
	if (s[i + j] == '.')
		param = ft_precision (s, (i + j - 1), param);
	else
	{
		param.converter = s[i + j];
		param.position = i + j;
	}
	return (param);
}

t_flags	ft_identify(const char *s, int i, t_flags param)
{
	if(ft_isclass(s[i + 1]) == 1)
	{
		param.converter = s[i + 1];
		param.position = i + 1;
	}
	else if(s[i + 1] == '.')
		param = ft_precision(s, i, param);
	else if(s[i + 1] >= '1' & s[i + 1] <= '9')
		param = ft_width(s, i, param);
	else if(s[i + 1] == '0')
	{
		param.zero = 1;
		param = ft_width(s, i + 1, param);
	}
	else if(s[i + 1] == '-')
	{
		param.minus = 1;
		if (s[i + 2] == '0')
		{
			param.zero = 1;
			param = ft_width(s, i + 2, param);
		}
		else
			param = ft_width(s, i + 1, param);
	}
/*	printf("converter: %c\n", param.converter);
	printf("precision: %d\n", param.precision);
	printf("width: %d\n", param.width);
	printf("zero: %d\n", param.zero);
	printf("minus: %d\n", param.minus);
	printf("position: %d\n", param.position);
*/	return (param);
}

void	ft_putdata(t_flags param, va_list lst)
{
	ft_putchar('k');
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

	ft_printf("R=%-010.13d\n", a);
//	printf("Printf_Oficial=%d\n", a);

	return (0);
}
