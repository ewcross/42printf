/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/12/05 18:56:22 by ecross           ###   ########.fr       */
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

	int a = 0;
	wchar_t wch = atoi(v[1]);

	ft_printf(" --> %d\n", ft_printf("mine:...%d...%lc", 5,  wch,));
	printf(" --> %d\n", printf("real:...%d...%lc", 5,  wch,));

	(void)v;
	return (0);
}
