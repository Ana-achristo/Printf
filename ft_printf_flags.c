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
	param.dot = 0;
	param.position = 0;
	return (param);
}

t_flags	ft_number(const char *s, int j, t_flags param, int worp)
{
	int sum;

	sum = 0;
	while (ft_isnumber(s[j]) == 1)
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

t_flags	ft_checknumber(const char *s, int j, t_flags param)
{
	if ((s[j] == '0') & (ft_isnumber(s[j - 1]) == 0))
		param.zero = 1;
	else
		param = ft_number(s, j, param, 0);
	return (param);
}

t_flags	ft_identify_end(const char *s, int j, t_flags param)
{
	if (param.minus == 1)
		param.zero = 0;
	if (ft_isclass(s[j]) == 1)
		param.converter = s[j];
	param.position = j;
	return (param);
}

t_flags	ft_identify(const char *s, int j, t_flags param)
{
	int	len;
	
	j = j + 1;
	len = ft_strlen (s);
	while ((ft_isclass(s[j]) == 0) & (j < len))
	{
		if ((s[j] == '.') & (ft_isnumber(s[j + 1]) == 1))
			param = ft_number(s, j + 1, param, 1);
		else if ((s[j] == '.') & (s[j + 1] == '*'))
			param.starp = 1;
		else if ((s[j] == '*') & (s[j - 1] != '.'))
			param.starw = 1;
		else if (ft_isnumber(s[j]) == 1)
			param = ft_checknumber(s, j, param);
		else if (s[j] == '-')
			param.minus = 1;
		if (s[j] == '.')
			param.dot = 1;
		if (param.position != 0)
		{
			j = param.position;
			param.position = 0;
		}
		else
			j++;
	}
	param = ft_identify_end(s, j, param);
	return (param);
}
