#include "printf.h"

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
		if (s[i + 2] == '-')
		{
			param.minus = 1;
			param = ft_width (s, i + 2, param);
		}
		else
			param = ft_width(s, i + 1, param);
	}
	else if(s[i + 1] == '-')
	{
		param.minus = 1;
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
