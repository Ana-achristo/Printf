NAME = abc

SRC = ft_printf.c ft_printf_utils.c ft_itoa.c ft_itoa_base.c ft_itoa_unsigned.c

INCLUDES = printf.h

all:
	gcc $(SRC) $(INCLUDES)

clean: 
	rm -f *.o

fclean: 
	clean
	rm -f $(NAME)

re: 
	fclean all
