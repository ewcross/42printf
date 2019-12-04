/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 13:32:05 by ecross           ###   ########.fr       */
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
	(void)v;
	
	setlocale(LC_NUMERIC, "en_GB");

	double d = 0.0000000000000001;
	printf("double %lu\n", sizeof(double));
	printf("long double %lu\n", sizeof(long double));
	/*ft_printf("mine: %.15g\n", d);
	printf("real: %.15g\n", d);*/
}
