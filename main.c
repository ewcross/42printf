/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/11/30 15:20:31 by elliotcro        ###   ########.fr       */
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

	ft_printf("mine: %.15e\n",  0.999999999999999000);
	printf("real: %.15e\n",  0.999999999999999000);
	ft_printf("mine: %.15e\n",  1.000000000000001);
	printf("real: %.15e\n",  1.000000000000001);
	ft_printf("mine: %.15e\n",  0.000000000000001);
	printf("real: %.15e\n",  0.000000000000001);
}
