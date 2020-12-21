/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:46:08 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:46:10 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i = i + 1;
	}
	return (i);
}

int		ft_isclass(char c)
{
	char	*class;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!(class = ft_strdup("cspdiuxX%\n")))
		return (0);
	while (i < 10)
	{
		if (class[i] == c)
			res = 1;
		i++;
	}
	free(class);
	return (res);
}

int		ft_isnumber(char c)
{
	char	*numbers;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!(numbers = ft_strdup("0123456789")))
		return (0);
	while (i < 10)
	{
		if (numbers[i] == c)
			res = 1;
		i++;
	}
	free(numbers);
	return (res);
}
