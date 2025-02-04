/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:45:11 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:45:12 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width_c(char value, int width, char c, int minus)
{
	int i;

	i = 1;
	if (minus == 1)
		ft_putchar(value);
	while (i < width)
	{
		ft_putchar(c);
		i++;
	}
	if (minus == 0)
		ft_putchar(value);
	return (i);
}

int	ft_printf_c(t_flags param, va_list lst)
{
	char	value;
	char	empty;
	int		n_add;

	empty = ' ';
	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.converter == '%')
		value = '%';
	else if (param.converter == '\n')
		value = '\n';
	else
		value = va_arg(lst, int);
	if (param.zero == 1)
		empty = '0';
	n_add = ft_print_width_c(value, param.width, empty, param.minus);
	return (n_add);
}
