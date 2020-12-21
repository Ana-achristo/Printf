/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:43:21 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:44:10 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_number(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		n = n + 1;
	if (n < 0)
	{
		size = size + 1;
		n = n * -1;
	}
	while (n / 10 > 0)
	{
		size = size + 1;
		n = n / 10;
	}
	size = size + 1;
	return (size);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*s;

	size = ft_size_number(n);
	if (!(s = malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	s[size] = '\0';
	size = size - 1;
	while (size >= i)
	{
		if (n < 0)
			s[size] = (n % 10) * -1 + 48;
		else
			s[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (s);
}
