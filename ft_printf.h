#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	int	starw;
	int	width;
	int	minus;
	int	zero;
	int	starp;
	int	precision;
	char	converter;
	int	newline;
	int	position;

}		t_flags;


int	ft_strlen(char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_substr(char *s, int start, int len);
void	ft_printf(const char *format, ...);
t_flags	ft_flags_init(t_flags param);
t_flags	ft_identify(const char *s, int j, t_flags param);
void	ft_print(char *value, int width, char c, int minus);
int	ft_printf_c(t_flags param, va_list lst);
void	ft_printf_s(t_flags param, va_list lst);
void	ft_printf_d(t_flags param, va_list lst);
void	ft_printf_u(t_flags param, va_list lst);
void	ft_printf_x(t_flags param, va_list lst, char a);
void	ft_printf_p(t_flags param, va_list lst, char a);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_base(unsigned long int n, int base, char a);

#endif
