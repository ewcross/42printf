/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/12/05 17:06:28 by ecross           ###   ########.fr       */
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

	wchar_t wint = 'h';

	setlocale(LC_NUMERIC, "en_GB");

	int a = 0;
	wchar_t *s = L"hello";
	/*while (a < 300)
	{
		printf("a = %d[%d]\n", a, printf("%lc", a));
		a++;
	}*/

	ft_printf("%ls\n", s);
	printf("%ls", s);

	return (0);
}
