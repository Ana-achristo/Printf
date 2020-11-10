#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char* s);
int	printf_ana(const char *format, ...);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);

#endif
