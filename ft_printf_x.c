/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:45:39 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:45:41 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(t_flags param, va_list lst, char a)
{
	int		value_x;
	char	*value;
	char	empty;
	int		n_add;
	char	*value_new;

	empty = ' ';
	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_x = va_arg(lst, int);
	if ((value_x == 0) & (param.dot == 1) & (param.precision == 0))
		value = ft_substr("", 0, 0);
	else
		value = ft_itoa_base((unsigned int)value_x, 16, a);
	value_new = ft_strcomplete(value, param.precision);
	if ((param.zero == 1) & (param.dot == 0))
		empty = '0';
	n_add = ft_print(value_new, param.width, empty, param.minus);
	free(value_new);
	free(value);
	return (n_add);
}
