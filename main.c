#include "printf.h"

int main()
{
/*	// Teste c
	char	c = 'a';

	ft_printf("Teste: c\n");
	ft_printf("Meu=%c\n", c);
	printf("Ofi=%c\n\n", c);

	ft_printf("Teste: 5c\n");
	ft_printf("Meu=%5c\n", c);
	printf("Ofi=%5c\n\n", c);

	ft_printf("Teste: -5c\n");
	ft_printf("Meu=%-5c\n", c);
	printf("Ofi=%-5c\n\n", c);

	ft_printf("Teste: 05c\n");
	ft_printf("Meu=%05c\n", c);
	printf("Ofi=%05c\n\n", c);

	ft_printf("Teste: *c,5\n");
	ft_printf("Meu=%*c\n",5, c);
	printf("Ofi=%*c\n\n", 5,c);

	ft_printf("Teste: c, c\n");
	ft_printf("Meu=%c, %c\n", c, c);
	printf("Ofi=%c, %c\n", c, c);

	// Teste s
	char	*s = "abcdef";

	ft_printf("Teste: s\n");
	ft_printf("Meu=%s\n", s);
	printf("Ofi=%s\n\n", s);

	ft_printf("Teste: 5s\n");
	ft_printf("Meu=%5s\n", s);
	printf("Ofi=%5s\n\n", s);

	ft_printf("Teste: s\n");
	ft_printf("Meu=%10s\n", s);
	printf("Ofi=%10s\n\n", s);

	ft_printf("Teste: -10s\n");
	ft_printf("Meu=%-10s\n", s);
	printf("Ofi=%-10s\n\n", s);

	ft_printf("Teste: 010s\n");
	ft_printf("Meu=%010s\n", s);
	printf("Ofi=%010s\n\n", s);

	ft_printf("Teste:- 010s\n");
	ft_printf("Meu=%-010s\n", s);
	printf("Ofi=%-010s\n\n", s);
	
	ft_printf("Teste: *s,10\n");
	ft_printf("Meu=%*s\n",10, s);
	printf("Ofi=%*s\n\n", 10,s);

	ft_printf("Teste: s, s\n");
	ft_printf("Meu=%s, %s\n", s, s);
	printf("Ofi=%s, %s\n", s, s);

	ft_printf("Teste: 10.3s\n");
	ft_printf("Meu=%10.3s\n", s);
	printf("Ofi=%10.3s\n\n", s);

	ft_printf("Teste: *.*s, 10, 3\n");
	ft_printf("Meu=%*.*s\n", 10, 3, s);
	printf("Ofi=%*.*s\n\n", 10, 3, s);
*/
	// Teste d
	int d = 543;

	ft_printf("Teste: d\n");
	ft_printf("Meu=%d\n", d);
	printf("Ofi=%d\n\n", d);

	ft_printf("Teste: 5d\n");
	ft_printf("Meu=%5d\n", d);
	printf("Ofi=%5d\n\n", d);

	ft_printf("Teste: -5d\n");
	ft_printf("Meu=%-5d\n", d);
	printf("Ofi=%-5d\n\n", d);

	ft_printf("Teste: 05d\n");
	ft_printf("Meu=%05d\n", d);
	printf("Ofi=%05d\n\n", d);

	ft_printf("Teste:-05d\n");
	ft_printf("Meu=%-05d\n", d);
	printf("Ofi=%-05d\n\n", d);
	
	ft_printf("Teste: *d,5\n");
	ft_printf("Meu=%*d\n",5, d);
	printf("Ofi=%*d\n\n", 5,d);

	ft_printf("Teste: d, d\n");
	ft_printf("Meu=%d, %d\n", d, d);
	printf("Ofi=%d, %d\n\n", d,d);

	ft_printf("Teste: 5.2d\n");
	ft_printf("Meu=%5.2d\n", d);
	printf("Ofi=%5.2d\n\n", d);

	ft_printf("Teste: *.*d,5, 2\n");
	ft_printf("Meu=%*.*d\n",5, 2, d);
	printf("Ofi=%*.*d\n\n", 5, 2,d);

	return (0);
}

