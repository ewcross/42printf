/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/11/26 13:37:03 by elliotcro        ###   ########.fr       */
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
	float f = 10.2;
	(void)c;

	setlocale(LC_NUMERIC, "en_GB");

    ft_printf("mine: ...%.15f\n", 0.87650894254);
    printf("real: ...%.15f\n", 0.87650894254);
    ft_printf("mine: ...%.16f\n", 0.999999999999999900);
    printf("real: ...%.16f\n", 0.999999999999999900);
    ft_printf("mine: ...%.18f\n", 0.125978548534310421);
    printf("real: ...%.18f\n", 0.125978548534310421);
	
	(void)v;
	return (0);
}
