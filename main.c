/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/12/02 15:12:50 by elliotcro        ###   ########.fr       */
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

	double d = 0.999999;
	ft_printf("mine: %g\n", d);
	printf("real: %g\n", d);
}
