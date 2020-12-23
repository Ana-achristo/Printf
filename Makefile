# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achristo <achristo@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 20:44:34 by achristo          #+#    #+#              #
#    Updated: 2020/12/22 21:03:57 by achristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_itoa.c ft_itoa_base.c \
       ft_itoa_unsigned.c ft_printf_flags.c ft_printf_c.c \
       ft_printf_s.c ft_printf_print.c ft_printf_d.c ft_printf_u.c \
       ft_printf_x.c ft_printf_p.c ft_printf_extra.c

 
OBJECTS = ft_printf.o ft_printf_utils.o ft_itoa.o ft_itoa_base.o \
		  ft_itoa_unsigned.o ft_printf_flags.o ft_printf_c.o \
		  ft_printf_s.o ft_printf_print.o ft_printf_d.o ft_printf_u.o \
		  ft_printf_x.o ft_printf_p.o ft_printf_extra.o

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(LIB)
	@gcc -Wextra -Werror -Wall -c -g -I . $(SRCS) $(LIB)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ft_printf.h.gch

re: fclean all
