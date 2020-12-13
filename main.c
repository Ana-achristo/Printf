#include "ft_printf.h"

int main()
{
	// Teste c
/*	char	c = 'a';

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
	printf("Ofi=%c, %c\n\n", c, c);

	ft_printf("Teste: -05c\n");
	ft_printf("Meu=%-05c\n",c);
	printf("Ofi=%-05c\n", c);

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

	// Teste d e i
	int d = 543;

	ft_printf("Teste: i\n");
	ft_printf("Meu=%i\n", d);
	printf("Ofi=%i\n\n", d);

	ft_printf("Teste: 5d\n");
	ft_printf("Meu=%5d\n", d);
	printf("Ofi=%5d\n\n", d);

	ft_printf("Teste: -5i\n");
	ft_printf("Meu=%-5i\n", d);
	printf("Ofi=%-5i\n\n", d);

	ft_printf("Teste: 05d\n");
	ft_printf("Meu=%05d\n", d);
	printf("Ofi=%05d\n\n", d);

//	ft_printf("Teste:-05d\n");
//	ft_printf("Meu=%-05d\n", d);
//	printf("Ofi=%-05d\n\n", d);
	
	ft_printf("Teste: *i,5\n");
	ft_printf("Meu=%*i\n",5, d);
	printf("Ofi=%*i\n\n", 5,d);

	ft_printf("Teste: d, d\n");
	ft_printf("Meu=%d, %d\n", d, d);
	printf("Ofi=%d, %d\n\n", d,d);

	ft_printf("Teste: 5.2d\n");
	ft_printf("Meu=%5.2d\n", d);
	printf("Ofi=%5.2d\n\n", d);

	ft_printf("Teste: *.*d,5, 2\n");
	ft_printf("Meu=%*.*d\n",5, 2, d);
	printf("Ofi=%*.*d\n\n", 5, 2,d);

	// Teste u
	unsigned int u = 123;

	ft_printf("Teste: u\n");
	ft_printf("Meu=%u\n", u);
	printf("Ofi=%u\n\n", u);

	ft_printf("Teste: 5u\n");
	ft_printf("Meu=%5u\n", u);
	printf("Ofi=%5u\n\n", u);

	ft_printf("Teste: -5u\n");
	ft_printf("Meu=%-5u\n", u);
	printf("Ofi=%-5u\n\n", u);

	ft_printf("Teste: 05u\n");
	ft_printf("Meu=%05u\n", u);
	printf("Ofi=%05u\n\n", u);

	ft_printf("Teste:-05u\n");
	ft_printf("Meu=%-05u\n", u);
	printf("Ofi=%-05u\n\n", u);
	
	ft_printf("Teste: *u,5\n");
	ft_printf("Meu=%*u\n",5, u);
	printf("Ofi=%*u\n\n", 5,u);

	ft_printf("Teste: u, u\n");
	ft_printf("Meu=%u, %u\n", u, u);
	printf("Ofi=%u, %u\n\n", u,u);

	ft_printf("Teste: 5.2u\n");
	ft_printf("Meu=%5.2u\n", u);
	printf("Ofi=%5.2u\n\n", u);

	ft_printf("Teste: *.*u,5, 2\n");
	ft_printf("Meu=%*.*u\n",5, 2, u);
	printf("Ofi=%*.*u\n\n", 5, 2,u);

	// Teste x, X
	int x = 0x1A2B3C4D;

	ft_printf("Teste: x\n");
	ft_printf("Meu=%x\n", x);
	printf("Ofi=%x\n\n", x);

	ft_printf("Teste: 10X\n");
	ft_printf("Meu=%10X\n", x);
	printf("Ofi=%10X\n\n", x);

	ft_printf("Teste: -10x\n");
	ft_printf("Meu=%-10x\n", x);
	printf("Ofi=%-10x\n\n", x);

	ft_printf("Teste: 010x\n");
	ft_printf("Meu=%010x\n", x);
	printf("Ofi=%010x\n\n", x);

	ft_printf("Teste:-010x\n");
	ft_printf("Meu=%-010x\n", x);
	printf("Ofi=%-010x\n\n", x);
	
	ft_printf("Teste: *X,10\n");
	ft_printf("Meu=%*X\n",10, x);
	printf("Ofi=%*X\n\n", 10,x);

	ft_printf("Teste: x, x\n");
	ft_printf("Meu=%x, %x\n", x, x);
	printf("Ofi=%x, %x\n\n", x, x);

	ft_printf("Teste: 10.2X\n");
	ft_printf("Meu=%10.2X\n", x);
	printf("Ofi=%10.2X\n\n", x);

	ft_printf("Teste: *.*x, 10, 2\n");
	ft_printf("Meu=%*.*x\n",10, 2, x);
	printf("Ofi=%*.*x\n\n", 10, 2,x);

	
	// Teste p
	char *p;

	ft_printf("Teste: p\n");
	ft_printf("Meu=%p\n", &p);
	printf("Ofi=%p\n\n", &p);

	ft_printf("Teste: 20p\n");
	ft_printf("Meu=%20p\n", &p);
	printf("Ofi=%20p\n\n", &p);

	ft_printf("Teste: -20p\n");
	ft_printf("Meu=%-20p\n", &p);
	printf("Ofi=%-20p\n\n", &p);

	ft_printf("Teste: 020p\n");
	ft_printf("Meu=%020p\n", &p);
	printf("Ofi=%020p\n\n", &p);

	ft_printf("Teste:-020p\n");
	ft_printf("Meu=%-020p\n", &p);
	printf("Ofi=%-020p\n\n", &p);
	
	ft_printf("Teste: *p,20\n");
	ft_printf("Meu=%*p\n",20, &p);
	printf("Ofi=%*p\n\n", 20,&p);

	ft_printf("Teste: p, p\n");
	ft_printf("Meu=%p, %p\n", &p, &p);
	printf("Ofi=%p, %p\n\n", &p, &p);

	ft_printf("Teste: 10.2p\n");
	ft_printf("Meu=%10.2p\n", &p);
	printf("Ofi=%10.2p\n\n", &p);

	ft_printf("Teste:.20p\n");
	ft_printf("Meu=%.20p\n", &p);
	printf("Ofi=%.20p\n\n", &p);

	//Teste precisão
	char	*p;

//	printf("Ofi = %.5s\n", "abc");
//	printf("Ofi = %.5d\n", 534);
//	printf("Ofi = %.*d\n", -6,123);
//	printf("Ofi = %.d, %.d\n", 5, 0);
//	printf("Ofi = %.5x\n", 0x1a2b);
//	printf("Ofi = %.5i\n", 543);
//	printf("Ofi = %.25p\n", &p);


//	ft_printf("Meu = %.5s\n", "abc");
	ft_printf("Meu = %.5d\n", 534);
	ft_printf("Meu = %.*d\n", -6,123);
//	ft_printf("Meu = %.d, %.d\n", 5, 0);


//	printf("Ofi = %*d\n", -4, 6);
//	ft_printf("Meu = %*d\n", -4, 6);

	printf("Ofi = %0*.*d\n", 5, 3, -12);
	ft_printf("Meu = %0*.*d\n", 5, 3, -12);

	printf("Ofi = %0*.d\n", 5, -12);
	ft_printf("Meu = %0*.d\n", 5, -12);

	printf("Ofi = %*s\n",-5, "abc");
	ft_printf("Meu = %*s\n",-5, "abc");

	char	*q = "0";
	int	i = 16;	

//	printf("Ofi = %.*x\n", -1, i);
//	ft_printf("Meu = %.*x\n", -1, i);
	printf("Ofi = %.*s\n", 3, q);
	ft_printf("Meu = %.*s\n", 3, q);

//	char	*p;
	int n;
	int m;
	

//	n = printf("Ofi = %*p\n", 10, NULL);
//	m = ft_printf("Meu = %*p\n", 10, NULL);


	n = printf(NULL);
	m = ft_printf(NULL);
	printf("n= %d, m= %d\n", n, m);

	printf("teste larg=5\n");
	printf("%5%\n");
	ft_printf("%5%\n");

	printf("teste larg=5 e flag0\n");
	printf("%05%\n");
	ft_printf("%05%\n");

	printf("teste larg=6 e flag-0\n");
	printf("%-06%\n");
	ft_printf("%-06%\n");

	printf("teste larg=5 e flag*\n");
	printf("%*%\n", 5);
	ft_printf("%*%\n", 5);

//	printf("teste precisão = 0\n");
//	printf("%.0%\n");
//	ft_printf("%.0%\n");

*/
//	char *p;

	printf("%.p\n", NULL);
	ft_printf("%.p\n", NULL);
	return (0);
}

