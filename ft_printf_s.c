/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:46:57 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:46:58 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(t_flags param, va_list lst)
{
	char	*value;
	int		n_add;
	char	*value_new;
	char	*value_new2;

	if (param.starw == 1)
		param = ft_read_star(lst, 0, param);
	if (param.starp == 1)
		param = ft_read_star(lst, 1, param);
	value = va_arg(lst, char*);
	if (value == NULL)
		value_new = ft_substr("(null)", 0, 6);
	else
		value_new = ft_substr(value, 0, ft_strlen(value));
	if (param.dot == 1)
		value_new2 = ft_substr(value_new, 0, param.precision);
	else
		value_new2 = ft_substr(value_new, 0, ft_strlen(value_new));
	if ((param.zero == 1) & (param.dot == 0))
		n_add = ft_print(value_new2, param.width, '0', param.minus);
	else
		n_add = ft_print(value_new2, param.width, ' ', param.minus);
	free(value_new);
	free(value_new2);
	return (n_add);
}
