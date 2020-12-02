#include "ft_printf.h"

t_flags	ft_flags_init(t_flags param)
{
	param.starw = 0;
	param.width = 0;
	param.minus = 0;
	param.zero = 0;
	param.starp = 0;
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

int	ft_isnumber(char c)
{
	char	*numbers;
	int	i;
	int	res;

	i = 0;
	numbers = "0123456789";
	res = 0;
	while (i <= 10)
	{
		if(numbers[i] == c)
			res = 1;
		i++;
	}
	return (res);
}

t_flags ft_number(const char *s, int j, t_flags param, int worp)
{
	int sum;

	sum = 0;
	while(ft_isnumber(s[j]) == 1)
	{
		sum = 10 * sum + s[j] - '0';
		j++;
	}
	if (worp == 1)
		param.precision = sum;
	else
		param.width = sum;
	param.position = j;
	return (param);
}

t_flags	ft_identify(const char *s, int j, t_flags param)
{
	j = j + 1;
	while ((ft_isclass(s[j]) == 0) & (s[j] != '\0'))
	{
		if ((s[j] == '.') & (ft_isnumber(s[j + 1]) == 1))
			param = ft_number(s, j + 1, param, 1);
		else if ((s[j] == '.') & (s[j + 1] == '*'))
			param.starp = 1;
		else if ((s[j] == '*') & (s[j - 1] != '.'))
			param.starw = 1;
		else if (ft_isnumber(s[j]) == 1)
		{
			printf("cheguei");
			if ((s[j] == '0') & (ft_isnumber(s[j - 1])== 0))
				param.zero = 1;
			else
				param = ft_number(s, j, param, 0);
		}		
		else if (s[j] == '-')
		       		param.minus = 1;
		if (param.position != 0)
		{
			j = param.position;
			param.position = 0;
		}
		else
				j++;
	}
	if(param.minus == 1)
		param.zero = 0;
	if (ft_isclass(s[j]) == 1)
		param.converter = s[j];
	param.position = j;

/*	printf("width: %d\n", param.width);
	printf("minus: %d\n", param.minus);
	printf("zero: %d\n", param.zero);
	printf("precision: %d\n", param.precision);
	printf("converter: %c\n", param.converter);
	printf("position: %d\n", param.position);
	printf("starw: %d\n", param.starw);
	printf("starp: %d\n", param.starp);
*/	return (param);
}
