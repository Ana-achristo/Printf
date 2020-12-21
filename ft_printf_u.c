/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:45:32 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:45:35 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(t_flags param, va_list lst)
{
	int		value_u;
	char	*value;
	char	empty;
	int		n_add;
	char	*value_new;

	empty = ' ';
	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value_u = va_arg(lst, unsigned int);
	if ((value_u == 0) & (param.dot == 1) & (param.precision == 0))
		value = ft_substr("", 0, 0);
	else
		value = ft_itoa_unsigned(value_u);
	value_new = ft_strcomplete(value, param.precision);
	if ((param.zero == 1) & (param.dot == 0))
		empty = '0';
	n_add = ft_print(value_new, param.width, empty, param.minus);
	free(value);
	free(value_new);
	return (n_add);
}
