/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/11/27 15:03:07 by ecross           ###   ########.fr       */
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

	ft_printf("mine: %e\n", 999.999999);
	printf("real: %e\n", 999.999999);
	ft_printf("mine: %e\n", -99.999999);
	printf("real: %e\n", -99.999999);
	ft_printf("mine: %'.4f\n", -99.999999);
	printf("real: %'.4f\n", -99.999999);

	setlocale(LC_NUMERIC, "en_GB");
}
