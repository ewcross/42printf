/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/11/26 14:25:07 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <locale.h>

/*types: c s p di u x X f e n*/
/*
test ' flag with:
			- #
			- precision alone
			- precision with 0 flag
*/


int main(int argc, char **v)
{
	(void)argc;

	setlocale(LC_NUMERIC, "en_GB");
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	ft_printf(" --- Return : %d\n", ft_printf("Simple input test"));
	ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	ft_printf(" --- Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c)); //T3
	ft_printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c)); //T4
	ft_printf(" --- Return : %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c)); //T5
	ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c)); //T6
	ft_printf(" --- Return : %d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c)); //T7
	ft_printf(" --- Return : %d\n", ft_printf("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c)); //T8
	ft_printf(" --- Return : %d\n", ft_printf("%6i, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c)); //T9
	ft_printf(" --- Return : %d\n", ft_printf("%7i, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c)); //T10
	ft_printf(" --- Return : %d\n", ft_printf("%8i, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c)); //T11
	ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c)); //T12
	ft_printf(" --- Return : %d\n", ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c)); //T13
	ft_printf(" --- Return : %d\n", ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c)); //T14
	ft_printf(" --- Return : %d\n", ft_printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c)); //T15
	ft_printf(" --- Return : %d\n", ft_printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c)); //T16
	ft_printf(" --- Return : %d\n", ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c)); //T17
	ft_printf(" --- Return : %d\n", ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c)); //T18
	ft_printf(" --- Return : %d\n", ft_printf("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c)); //T19
	ft_printf(" --- Return : %d\n", ft_printf("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c)); //T20
	ft_printf(" --- Return : %d\n", ft_printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c)); //T21
	ft_printf(" --- Return : %d\n", ft_printf("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c)); //T22
	ft_printf(" --- Return : %d\n", ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c)); //T23
	ft_printf(" --- Return : %d\n", ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c)); //T24
	ft_printf(" --- Return : %d\n", ft_printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c)); //T25
	ft_printf(" --- Return : %d\n", ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c)); //T26
	ft_printf(" --- Return : %d\n", ft_printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c)); //T27
	ft_printf(" --- Return : %d\n", ft_printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d", i, j, k, l, m, c)); //T28
	ft_printf(" --- Return : %d\n", ft_printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c)); //T29
	ft_printf(" --- Return : %d\n", ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c)); //T30
	ft_printf(" --- Return : %d\n", ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c)); //T31
	ft_printf(" --- Return : %d\n", ft_printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c)); //T32
	ft_printf(" --- Return : %d\n", ft_printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c)); //T33
	while (a < 5) //T34-69
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c));
		ft_printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c));
		ft_printf(" --- Return : %d\n", ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c));
		ft_printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c));
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			b++;
		}
		a++;
	}
	a = 19;
	b = 14;
	ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42)); //T178
	ft_printf(" --- Return : %d\n", ft_printf("%12.12i, %12.12d", -42, 42)); //T179
	ft_printf(" --- Return : %d\n", ft_printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	ft_printf(" --- Return : %d\n", ft_printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	ft_printf(" --- Return : %d\n", ft_printf("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	ft_printf(" --- Return : %d\n", ft_printf("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	ft_printf(" --- Return : %d\n", ft_printf("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	ft_printf(" --- Return : %d\n", ft_printf("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	ft_printf(" --- Return : %d\n", ft_printf("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r));; //T186
	a = -4;
	while (a < 5) //T187-213
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			b++;
		}
		a++;
	}

	ft_printf(" --- Return : %d\n", ft_printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	a = -1;
	while (a < 5) //T214-256
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		ft_printf(" --- Return : %d\n", ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		ft_printf(" --- Return : %d\n", ft_printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		ft_printf(" --- Return : %d\n", ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		a++;
	}
	a = -1;
	while(a < 5) //T257-346
	{
		b = -1;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			ft_printf(" --- Return : %d\n", ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			b++;
		}
		a++;
	}
	ft_printf(" --- Return : %d\n", ft_printf("%p, %x, %p, %x, %p, %x", 209590960, 209590960, 207038912, 207038912, 1, 1)); //T347
	a = 8;
	while (a < 12) //
	{
		ft_printf(" --- Return : %d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1));
		ft_printf(" --- Return : %d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1));
		a++;
	}
	a = f;
	b = g;
	ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
	ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	ft_printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	ft_printf(" --- Return : %d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1));

	a = 12;
	b = 18;
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
	ft_printf(" --- Return : %d\n", ft_printf("%%, \t, \\, \", \', +"));
	ft_printf(" --- Return : %d\n", ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	ft_printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
//	ft_printf(" --- Return : %d\n", ft_printf("%-2s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	ft_printf(" --- Return : %d\n", ft_printf("(null)"));
	ft_printf(" --- Return : %d\n", ft_printf(""));

	(void)v;
	return (0);
}
