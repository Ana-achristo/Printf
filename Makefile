NAME = abc

SRC = ft_printf.c ft_printf_utils.c ft_itoa.c ft_itoa_base.c \
      ft_itoa_unsigned.c ft_printf_flags.c ft_printf_c.c \
      ft_printf_s.c ft_printf_print.c ft_printf_d.c main.c

INCLUDES = printf.h

all:
	gcc $(SRC) $(INCLUDES)
