/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/12/06 11:42:25 by ecross           ###   ########.fr       */
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

	wchar_t *wstr = 0;
	
	ft_printf(" --> %d\n", ft_printf("mine:...%d...%.2ls", 5,  wstr));
	printf(" --> %d\n", printf("real:...%d...%.2ls", 5,  wstr));
	ft_printf(" --> %d\n", ft_printf("mine:...%d...%.2lls", 5,  wstr));
	printf(" --> %d\n", printf("real:...%d...%.2lls", 5,  wstr));

	(void)v;
	return (0);
}
