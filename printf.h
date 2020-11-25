#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	int	width;
	int	minus;
	int	zero;
	int	precision;
	char	converter;
	int	newline;
	int	position;

}		t_flags;



void	ft_putchar(char c);
void	ft_putstr(char* s);
void	ft_printf(const char *format, ...);
t_flags	ft_flags_init(t_flags param);
t_flags	ft_identify(const char *s, int i, t_flags param);
int	ft_printf_c(t_flags param, va_list lst);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_base(int n, int base, char a);

#endif
