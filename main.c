/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/11/25 16:49:45 by ecross           ###   ########.fr       */
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
	double f = 10.227;
	unsigned char ch = 9;
	(void)c;

	setlocale(LC_NUMERIC, "en_GB");

	ft_printf("mine: ...%.2f...\n", f);
	printf("real: ...%.2f...\n", f);
	
	/*ft_printf("mine: d: %'012d\n", i);
	printf("real: d: %'012d\n", i);

	printf("------\n");
	
	ft_printf("mine: i: %+'012i\n", i);
	printf("real: i: %+'012i\n", i);
	
	printf("------\n");
	
	ft_printf("mine: u: %'012u\n", u);
	printf("real: u: %'012u\n", u);
	
	printf("------\n");
	
	ft_printf("mine: f: %+'012f\n", f);
	printf("real: f: %+'012f\n", f);
	
	printf("------\n");
	
	ft_printf("mine: p: %'030p\n", &f);
	printf("real: p: %'030p\n", &f);*/
	
	(void)v;
	return (0);
}
