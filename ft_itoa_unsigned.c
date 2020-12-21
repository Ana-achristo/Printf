/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:44:34 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:44:35 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_number_u(unsigned int n)
{
	int size;

	size = 0;
	while (n / 10 > 0)
	{
		size = size + 1;
		n = n / 10;
	}
	size = size + 1;
	return (size);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		size;
	char	*s;

	size = ft_size_number_u(n);
	if (!(s = malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (s == 0)
		return (0);
	s[size] = '\0';
	size = size - 1;
	while (size >= 0)
	{
		s[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (s);
}
