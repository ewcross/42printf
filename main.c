/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:54:47 by ecross             #+#    #+#            */
/*   Updated: 2019/11/22 12:59:04 by ecross           ###   ########.fr       */
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
	int i = 5423422;
	unsigned int u = 1234567;
	double f = 123.123;

	(void)c;

	setlocale(LC_NUMERIC, "en_GB");

	ft_printf("mine: %e\n", f);
	printf("real: %e\n", f);

	printf("------\n");

	ft_printf("mine: d %'12.8d\n", i);
	printf("real: d %'12.8d\n", i);

	/*printf("------\n");
	printf("i %+#12i\n", i);
	printf("------\n");
	printf("u %'#12u\n", u);
	printf("------\n");
	printf("f %'#.f\n", f);
	printf("------\n");
	printf("p %'#30p\n", &f);*/
	(void)v;
	return (0);
}
