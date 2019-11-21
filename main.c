/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:54:47 by ecross             #+#    #+#            */
/*   Updated: 2019/11/21 16:57:55 by ecross           ###   ########.fr       */
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


int main(int c, char **v)
{
	int i = 1234567;
	unsigned int u = 1234567;
	double f = 42.1234;

	(void)c;
	/*setlocale(LC_NUMERIC, "en_GB");
	printf("------\n");
	printf("d %'#12d\n", i);
	printf("------\n");
	printf("i %+#12i\n", i);
	printf("------\n");
	printf("u %'#12u\n", u);
	printf("------\n");
	printf("f %'#.f\n", f);
	printf("------\n");
	printf("p %'#30p\n", &f);*/
	ft_printf("f %.30f\n", f);
	printf("f %.30f\n", f);
	(void)v;
	return (0);
}
