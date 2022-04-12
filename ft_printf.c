#include <stdarg.h>
#include <unistd.h>
int	g_var = 0;
void	ft_putnbr(long dig, int len, char *sign) {
	if (dig >= len)
		ft_putnbr(dig/len, len, sign);
	write (1, &sign[dig % len], 1);
	g_var++;
}
int	ft_printf(const char *spec, ...) {
	va_list	ap;
	va_start(ap, spec);
	while (*spec) {
		if (*spec == '%') {
			spec++;
			if (*spec == 's') {
				int	len = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				va_end(ap);
				g_var += len;
				write(1, str, len);
			}
			else if (*spec == 'd') {
				int d = va_arg(ap, int);
				if (d < 0) {
					write(1, "-", 1);
					g_var++;
					d = -d;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			else if (*spec == 'x') {
				int x = va_arg(ap, unsigned);
				ft_putnbr(x, 16, "0123456789abcdef");
			}
			spec++;
		}
		else
			g_var += write(1, spec++, 1);
	}
	va_end(ap);
	return(g_var);
}
/*
int main(void) {
	int res;
	// char *str = NULL;
	// res = printf("%s","");
	res = printf("TEXT %d TEXT %d TEXT %x", -15, 11, 15);
	// res = printf("%s %d", "vsem priv",1115252523);
	printf("\n");
	printf("%d\n", res);
	// printf("%x", 17);
}*/
