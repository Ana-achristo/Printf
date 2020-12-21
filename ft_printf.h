/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:56:19 by achristo          #+#    #+#             */
/*   Updated: 2020/12/21 20:56:30 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	int		starw;
	int		width;
	int		minus;
	int		zero;
	int		starp;
	int		precision;
	char	converter;
	int		dot;
	int		position;

}				t_flags;

int				ft_isnumber(char c);
int				ft_isclass(char c);
char			*ft_strdup(char	*s);
size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strcomplete(const char *s, int precision);
int				ft_printf(const char *format, ...);
t_flags			ft_flags_init(t_flags param);
t_flags			ft_identify(const char *s, int j, t_flags param, int len);
int				ft_print(char *value, int width, char c, int minus);
int				ft_printf_c(t_flags param, va_list lst);
int				ft_printf_s(t_flags param, va_list lst);
int				ft_printf_d(t_flags param, va_list lst);
t_flags			ft_read_star(va_list lst, int worp, t_flags param);
int				ft_printf_u(t_flags param, va_list lst);
int				ft_printf_x(t_flags param, va_list lst, char a);
int				ft_printf_p(t_flags param, va_list lst, char a);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_itoa_base(unsigned long int n, int base, char a);

#endif
