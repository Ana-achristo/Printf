/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:45:55 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:45:56 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfirst(char *value)
{
	int	n_add;

	n_add = 0;
	if (value[0] == '-')
		ft_putchar('-')	;
	if (value[0] == '0')
	{
		ft_putchar('0');
		ft_putchar('x');
		n_add = 1;
	}
	n_add = n_add + 1;
	return (n_add);
}

int	ft_putempty(char c, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	ft_print(char *value, int width, char c, int minus)
{
	int		len;
	int		n_add;
	char	*aux;

	n_add = 0;
	len = ft_strlen(value);
	width = width - len;
	if (c == '0')
	{
		if ((value[0] == '-') || ((value[0] == '0') & (value[1] == 'x')))
			n_add = ft_printfirst(value);
		aux = ft_substr(value, n_add, (len - n_add));
	}
	else
		aux = ft_substr(value, 0, len);
	if (minus == 1)
		n_add = ft_putstr(aux);
	n_add = n_add + ft_putempty(c, width);
	if (minus == 0)
		n_add = n_add + ft_putstr(aux);
	free(aux);
	return (n_add);
}
