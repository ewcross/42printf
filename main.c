/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 17:42:12 by ecross           ###   ########.fr       */
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

	ft_printf("mine: ...%06.6f...\n", INFINITY);
	printf("real: ...%06.6f...\n", INFINITY);
	ft_printf("mine: ...%f...\n", NAN);
	printf("real: ...%f...\n", NAN);
}
