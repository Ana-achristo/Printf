/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:44:25 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:44:27 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_number_b(unsigned long int n, int base)
{
	int size;

	size = 0;
	while ((n / base) > 0)
	{
		size = size + 1;
		n = n / base;
	}
	size = size + 1;
	return (size);
}

char	*ft_itoa_base(unsigned long int n, int base, char a)
{
	int		size;
	char	*s;

	size = ft_size_number_b(n, base);
	if (!(s = malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (s == 0)
		return (0);
	s[size] = '\0';
	size = size - 1;
	while (size >= 0)
	{
		if ((n % base) <= 9)
			s[size] = n % base + 48;
		else
			s[size] = n % base + a - 10;
		n = n / base;
		size--;
	}
	return (s);
}
